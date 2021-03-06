# Created by:	Jason Bacon
# $FreeBSD$

PORTNAME=	lammps
PORTVERSION=	2016.05.14
CATEGORIES=	science
# FIXME: Can this be done from http://lammps.sandia.gov/download.html#tar?
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Large-scale Atomic/Molecular Massively Parallel Simulator

LICENSE=	GPLv1

# Need voro++ built with gcc or link will fail - use wip
LIB_DEPENDS+=	libfftw3.so:math/fftw3 \
		libjpeg.so:graphics/jpeg \
		libkim-api-v1.so:/usr/wip/science/openkim
BUILD_DEPENDS+=	${LOCALBASE}/lib/liblapack.a:math/lapack \
		${LOCALBASE}/lib/libblas.a:math/blas \
		${LOCALBASE}/lib/libvoro++.a:/usr/wip/science/voro++

BUILD_WRKSRC=	${WRKSRC}/src

# Allow MPI slave ports to override
# MPI-dependent ports install to ${PREFIX}/mpi/<mpi-implementation>
# so that they don't conflict with serial versions of the same port
# or versions built for other MPI implementations, and all ports using
# the same MPI implementation share a common PATH, LDFLAGS, etc.  This
# is critical on clusters and grids with multiple users who use different
# MPI implementations.
INSTALL_PREFIX?=${PREFIX}

# Selects a system-specific Makefile.  Allow MPI slave ports to override.
ALL_TARGET?=	FreeBSD-serial

USES=		gmake fortran tar:xz
USE_GCC=	yes

# Prevent slave ports from including master plist
PLIST=	${.CURDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-patch:
	@${CP} ${FILESDIR}/Makefile.${ALL_TARGET} ${BUILD_WRKSRC}/MAKE

post-patch:
	@${REINPLACE_CMD} \
		-e "s|g++|${CXX}|g" \
		-e "s|LOCALBASE|${LOCALBASE}|g" \
		-e "s|_GCC_BUILD_DEPENDS|${_GCC_BUILD_DEPENDS}|g" \
		${BUILD_WRKSRC}/MAKE/Makefile.${ALL_TARGET}
	@${REINPLACE_CMD} \
		-e "s|/bin/bash|/bin/sh|g" \
		${BUILD_WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e "s|gcc|${CC}|g" \
		-e "s|g++|${CXX}|g" \
		-e "s|gfortran|${FC}|g" \
		-e "s|ifort|${FC}|g" \
		-e "s|-march=native -mpc64|-fPIC|g" \
		-e "s|\.exe||g" \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/tools/msi2lmp/src/Makefile \
		${BUILD_WRKSRC}/STUBS/Makefile \
		${WRKSRC}/lib/*/Makefile.serial \
		${WRKSRC}/lib/*/Makefile.g++ \
		${WRKSRC}/lib/*/Makefile.gfortran
	@${REINPLACE_CMD} \
		-e "s|-Iopenkim-api-vX.X.X/KIM_API|-I${LOCALBASE}/include/kim-api-v1|g" \
		-e "s|-Lopenkim-api-vX.X.X/KIM_API|-L${LOCALBASE}/lib|g" \
		-e "s|-lkim|-lkim-api-v1|g" \
		-e "s|kim-api-build-config|kim-api-v1-build-config|g" \
		${BUILD_WRKSRC}/KIM/Makefile.lammps
	@${CP} ${WRKSRC}/lib/meam/Makefile.lammps.gfortran \
		${WRKSRC}/lib/meam/Makefile.lammps.${FC}
	@${CP} ${WRKSRC}/lib/reax/Makefile.lammps.gfortran \
		${WRKSRC}/lib/reax/Makefile.lammps.${FC}
	@${REINPLACE_CMD} \
		-e 's|IMOLPATH=""|IMOLPATH="${DATADIR}/moltemplate_common"|g' \
		${WRKSRC}/tools/moltemplate/src/moltemplate.sh

.if ${ALL_TARGET} == FreeBSD-openmpi
	@${REINPLACE_CMD} -e "s|mpic++|${LOCALBASE}/mpi/openmpi/bin/mpic++|g" \
		${WRKSRC}/lib/awpmd/Makefile.mpicc \
		${BUILD_WRKSRC}/MAKE/Makefile.${ALL_TARGET}
.endif

# Enable all possible standard packages
# Not included:
#   gpu: requires CUDA
do-build:
.for package in asphere body class2 colloid dipole fld granular kim kspace \
		manybody mc meam molecule opt peri poems replica \
		rigid shock srd voronoi xtc
	(cd ${BUILD_WRKSRC} && ${GMAKE} yes-${package})
.endfor
# reax package causes i386 lmp to abort immediately on startup
# It's unlikely that anyone will run LAMMPS on a 32-bit system anyway
.if ${ARCH} != "i386"
	(cd ${BUILD_WRKSRC} && ${GMAKE} yes-reax)
.endif
	(cd ${BUILD_WRKSRC} && ${GMAKE} package-status)
.if ${ALL_TARGET} == "FreeBSD-serial"
	(cd ${BUILD_WRKSRC} && ${GMAKE} stubs)
	(cd ${WRKSRC}/tools && ${GMAKE})
.endif
# Additional libs: Build before LAMMPS
.if ${ALL_TARGET} == "FreeBSD-openmpi"
	(cd ${WRKSRC}/lib/awpmd && ${GMAKE} -f Makefile.mpicc)
.endif
	(cd ${WRKSRC}/lib/atc && ${GMAKE} -f Makefile.serial)
	(cd ${WRKSRC}/lib/colvars && ${GMAKE} -f Makefile.g++)
	(cd ${WRKSRC}/lib/linalg && ${GMAKE} -f Makefile.gfortran)
	(cd ${WRKSRC}/lib/meam && ${GMAKE} -f Makefile.gfortran && \
		${CP} Makefile.lammps.gfortran Makefile.lammps)
	(cd ${WRKSRC}/lib/poems && ${GMAKE} -f Makefile.g++)
	(cd ${WRKSRC}/lib/reax && ${GMAKE} -f Makefile.gfortran && \
		${CP} Makefile.lammps.gfortran Makefile.lammps)
# Build LAMMPS
	(cd ${BUILD_WRKSRC} && ${GMAKE} ${MAKE_ARGS} ${ALL_TARGET})
# Additional tools
	(cd ${WRKSRC}/tools/msi2lmp/src && ${GMAKE} ${MAKE_ARGS})

# Users must set MOLTEMPLATE_PATH to "$DATADIR/moltemplate_common"
# FIXME: Replace CP with COPYTREE for proper permissions
do-install:
	${MKDIR} ${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_PROGRAM} \
		${BUILD_WRKSRC}/lmp_${ALL_TARGET} \
		${STAGEDIR}${INSTALL_PREFIX}/bin/lmp${PKGNAMESUFFIX}
.if ${ALL_TARGET} == "FreeBSD-serial"
	${MKDIR} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${EXAMPLESDIR} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/tools/binary2txt \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/chain \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/data2xmovie \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/micelle2d \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/msi2lmp/src/msi2lmp \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/moltemplate/src/*.sh \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/moltemplate/src/*.py \
		${STAGEDIR}${INSTALL_PREFIX}/bin
	${CP} -R ${WRKSRC}/tools/moltemplate/common \
		${STAGEDIR}${DATADIR}/moltemplate_common
.ifndef(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}
	${CHMOD} -R a+rX ${STAGEDIR}${DOSCDIR}
.endif
.ifndef(NOPORTEXAMPLES)
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/bench ${STAGEDIR}${EXAMPLESDIR}
	${CP} ${FILESDIR}/run-all-examples ${STAGEDIR}${EXAMPLESDIR}
	${CHMOD} -R a+rX ${STAGEDIR}${EXAMPLESDIR}
.endif
	${CP} -R ${WRKSRC}/potentials ${STAGEDIR}${DATADIR}
	${CHMOD} -R a+rX ${STAGEDIR}${DATADIR}
.endif

.include <bsd.port.post.mk>

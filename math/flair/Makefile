# New ports collection makefile for:	flair
# Date created:		13 Dec 2011
# Whom:			Jason Bacon <bacon4000@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	flair
PORTVERSION=	0.3.25
CATEGORIES=	math science
MASTER_SITES=	https://pantherfile.uwm.edu/weinert/www/flair.html/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	FLAPW method for bulk and thin films

# LICENSE=      Custom free software with restrictions

LIB_DEPENDS=	blas:math/blas \
		lapack:math/lapack \
		open-rte:net/openmpi

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_FORTRAN=	yes

MAKE_ENV+=	PATH=${PATH}:${PREFIX}/mpi/openmpi/bin

RESTRICTED=	Must request the source code at https://pantherfile.uwm.edu/weinert/www/flair.html

.include <bsd.port.pre.mk>

.if !defined(PACKAGE_BUILDING) && \
    !exists(${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX})
pre-everything::
	@${PRINTF} "\nPlease go to https://pantherfile.uwm.edu/weinert/www/flair.html to request the source distribution ${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} and place it in ${DISTDIR}.\n\n" | ${FMT}
	@${FALSE}
.endif

post-patch:
	${CP} -f ${FILESDIR}/Make.conf_openmpi-FreeBSD ${WRKSRC}/Make.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flair_inv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_complex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_soc_inv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_soc_complex ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_inv_mpi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_complex_mpi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_soc_inv_mpi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/flair_soc_complex_mpi ${PREFIX}/bin

.include <bsd.port.post.mk>

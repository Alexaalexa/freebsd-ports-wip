# Created by: Jason Bacon
# $FreeBSD: head/science/voro++/Makefile 345363 2014-02-21 10:29:52Z jhale $

PORTNAME=	voro++
PORTVERSION=	0.4.6
CATEGORIES=	science
MASTER_SITES=	http://math.lbl.gov/voro++/download/dir/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Three-dimensional computations of the Voronoi tessellation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
# LAMMPS linkage fails when using clang on 10.1-RC3
USE_GCC=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|CXX=|CXX?=|g' \
		-e 's|CFLAGS=|CFLAGS?=|g' \
		-e 's|PREFIX=.*|PREFIX?=|g' \
		${WRKSRC}/config.mk
	${REINPLACE_CMD} \
		-e 's|$$(PREFIX)|$$(DESTDIR)$$(PREFIX)|g' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/voro++

.include <bsd.port.mk>

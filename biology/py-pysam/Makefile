# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	pysam
PORTVERSION=	0.8.3
CATEGORIES=	biology
MASTER_SITES=	http://github.com/pysam-developers/pysam/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Python module for reading and manipulating samfiles

LICENSE=	MIT

# Currently does not build with cython 0.23
BUILD_DEPENDS=	cython:/usr/wip/lang/cython022

# Tested with python 2.5 and 2.6
# Still not finding ncurses
USES=		ncurses python:2
USE_PYTHON=	distutils
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Patch for cython 0.23
post-patch:
	${REINPLACE_CMD} -e 's|ctypedef enum|cdef enum|g' \
		${WRKSRC}/pysam/chtslib.pxd

.include <bsd.port.mk>

# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	htseq
PORTVERSION=	0.6.1p1
CATEGORIES=	python
MASTER_SITES=		${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/H/HTSeq
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	HTSeq-${PORTVERSION}

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Framework to analyze data from high-throughput sequencing assays

LICENSE=	GPLv3

BUILD_DEPENDS=	${PKGNAMEPREFIX}numpy>=1.9.2:math/py-numpy \
		${PKGNAMEPREFIX}matplotlib>=1.4.3:math/py-matplotlib

USES=		python
USE_PYTHON=	distutils

.include <bsd.port.mk>

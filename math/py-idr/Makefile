# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	idr
DISTVERSION=	2.0.3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	jwbacon@tds.net
COMMENT=	Estimating the copula mixture model and plotting correspondence curves

LICENSE=	GPLv2

# py-matplotlib does not build under py34 as of 2016-06-22
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:/usr/wip/math/py3-matplotlib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:/usr/wip/math/py3-matplotlib

USES=		python:3
USE_PYTHON=	distutils

USE_GITHUB=	yes
GH_ACCOUNT=	nboley

.include <bsd.port.mk>

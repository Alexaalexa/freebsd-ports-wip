# Created by: Jason Bacon <bacon@unixdev.ceas.uwm.edu>
# $FreeBSD$

PORTNAME=	busco
PORTVERSION=	1.22
CATEGORIES=	biology
MASTER_SITES=	http://busco.ezlab.org/files/
DISTNAME=	BUSCO_v${PORTVERSION}

MAINTAINER=	bacon@unixdev.ceas.uwm.edu
COMMENT=	Assess genome assembly and annotation completeness

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix
SHEBANG_FILES=	${WRKSRC}/${DISTNAME}.py

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/sample_data && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	GenomeAnalysisTK
PORTVERSION=	3.1
CATEGORIES=	biology science
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	jwbacon@tds.net
COMMENT=	Analyse next-generation resequencing data

USES=		tar:bzip2
USE_JAVA=	yes

RUN_DEPENDS+=	R:${PORTSDIR}/math/R

RESTRICTED=	License required for commercial use

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/*.jar ${STAGEDIR}${PREFIX}/bin
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	spark
PORTVERSION=	1.1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://d3kbcqa49mib13.cloudfront.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Fast and general-purpose cluster computing system

BUILD_DEPENDS+=	scala:lang/scala \
		${LOCALBASE}/share/java/maven31/bin/mvn:devel/maven31

BUILD_ENV+=	MAVEN_OPTS="-Xmx2g -XX:MaxPermSize=512M -XX:ReservedCodeCacheSize=512m"

do-build:
	cd ${WRKSRC} && mvn -Pyarn -Phadoop-2.4 -Dhadoop.version=2.4.1 -DskipTests clean package

.include <bsd.port.mk>

# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	star
PORTVERSION=	2.5.2a
CATEGORIES=	biology

MAINTAINER=	bacon4000@gmail.com
COMMENT=	RNA-seq aligner

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:openmp gmake
COMPILER_FEATURES+=      libc++

USE_GITHUB=	yes
GH_ACCOUNT=	alexdobin

# to_string() issue with all gcc versions
# http://stackoverflow.com/questions/26832199/getting-gcc-in-c11-mode-to-work-on-freebsd
CXXFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH -D_GLIBCXX_USE_C99_MATH_TR1

WRKSRC=		${WRKDIR}/STAR-${PORTVERSION}

PLIST_FILES=	bin/STAR

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/source/STAR ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

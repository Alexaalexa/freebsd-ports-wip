# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/devel/roboctl/Makefile 327726 2013-09-20 17:17:44Z bapt $

PORTNAME=	roboctl
PORTVERSION=	0.3.9
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	API and tools for communicating with Lego and Vex robots

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libgamepad.a:devel/libgamepad

MAKE_ENV=	EXTRALIBS=-lbluetooth
MAKE_JOBS_UNSAFE=	yes

USES=		tar:xz

OPTIONS_DEFINE=	CUTECOM
CUTECOM_DESC=	Install cutecom for Vex debugging

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCUTECOM}
RUN_DEPENDS+=	cutecom:comms/cutecom
.endif

pre-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} depend)

post-install:
	(cd ${WRKSRC}/Commands/NXTRemote; ${MAKE})
	${INSTALL_PROGRAM} ${WRKSRC}/Commands/NXTRemote/nxtremote ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/Scripts/lego_bluetooth_config ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Commands/NXTRemote/nxtremote.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

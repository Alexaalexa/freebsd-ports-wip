# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD: head/biology/bwa/Makefile 403676 2015-12-13 16:07:27Z swills $

PORTNAME=	bwa
PORTVERSION=	0.7.9a
CATEGORIES=	biology
MASTER_SITES=	SF/bio-bwa/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Burrows-Wheeler sequence aligner

LICENSE=	GPLv3

USES=		perl5 shebangfix tar:bzip2
SHEBANG_FILES=	qualfa2fq.pl xa2multi.pl
USE_PERL5=	run

PLIST_FILES=	bin/bwa bin/qualfa2fq.pl bin/xa2multi.pl man/man1/bwa.1.gz

# Avoid #error in emmintrin.h
# CFLAGS+=	-msse2
# Hack for Lenovo X120e
CFLAGS+=	-I/usr/include/clang/3.3

BROKEN_powerpc64=	Does not build on powerpc64

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bwa ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>

# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	stacks
PORTVERSION=	1.35
CATEGORIES=	biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	dsiercks@uwm.edu
COMMENT=	Software pipeline for building loci from short-read sequences

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

USES=		shebangfix
SHEBANG_FILES=	scripts/*.pl

.include <bsd.port.pre.mk>

# Something like this would be better, but it's not working
# USES=		compiler:c++11-lang
# CXXFLAGS+=	-std=gnu++11

.if ${OSVERSION} < 1000000
USE_GCC=	yes
.endif

#do-install:
#	${INSTALL_PROGRAM} ${WRKSRC}/clone_filter \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/cstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/estacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/genotypes \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/hstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/kmer_filter \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/phasedstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/populations \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/process_radtags \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/process_shortreads \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/pstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/rxstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/sstacks \
#	${STAGEDIR}${PREFIX}/bin
#	${INSTALL_PROGRAM} ${WRKSRC}/ustacks \
#	${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>

/* Mass Murderer aka Robot Fighter by Mike Ward*/
/* Note the Robot Fight code is lost, so the   */
/* 'rankings' will be wrong for that version.  */
/*Written in c99 by CLint Pulley*/
/*(C)1990 Seahorse Software*/
 
#include "dsk5.grf1rf"
 
#asm
       REF KSCAN,VWTR,VSBW,VMBW,DSRLNK,VMBR
PAB1   DATA >0500,>0000,>0000,>1800,>000D
       TEXT 'DSK1.MURDER_P'
DSRBUF BSS >900
#endasm
 
int pr[100], pc[100], cr[5], cc[5];
int pd[100], cd[5], prd[100], pcd[100];
int crd[5], ccd[5];
 
char rs[10][21];
 
int xn1,xn2,st; int ec,pn,x; int flag,y,a; int qw,r,c; int k,s,l,pl;
int n,pe;
 
#include "dsk5.random;c"
 
main()
{      flag=0;
       while (flag!=99)
       {
         define();
         while (flag!=2)
         {
           drmaze(l);
           inital();
           while (flag==0)
           {  player();
              if (flag==0)
              {    cop();
                   victim();
              }
           }
           if (flag==1)
              endlev();
           else
              gamovr();
         }
       }
}
 
title()
{#asm
       LI 0,>01A0
       BLWP @VWTR
       LI 0,>0002
       BLWP @VWTR
       LI 0,>0206
       BLWP @VWTR
       LI 0,>03FF
       BLWP @VWTR
       LI 0,>0403
       BLWP @VWTR
       LI 0,>0536
       BLWP @VWTR
       LI 0,>1B00
       LI 1,>D000
       BLWP @VSBW
       LI 0,>3700
       LI 1,DSRBUF
       LI 2,>900
       BLWP @VMBR
       LI 0,>1800
       CLR 2
NQ     CLR 1
LP     BLWP @VSBW
       INC 0
       AI 1,>0100
       CI 1,>0000
       JNE LP
       INC 2
       CI 2,3
       JNE NQ
       LI 0,>2000
       LI 1,>1F00
L2     BLWP @VSBW
       INC 0
       CI 0,>37D6
       JNE L2
       LI 0,>1B02
       LI 1,PAB1
       LI 2,24
       BLWP @VMBW
       LI 2,>1B0B
       MOV 2,@>8356
       BLWP @DSRLNK
       DATA 8
       LI 0,>01E2
       BLWP @VWTR
       LI 0,>37D6
       LI 1,>1F00
L3     BLWP @VSBW
       INC 0
       CI 0,>4000
       JNE L3
       LI 1,>0100
       MOVB 1,@>8374
WAIT   BLWP @KSCAN
       CLR 2
       MOVB @>8375,2
       CI 2,>1200
       JNE WAIT
       CLR 0
       BLWP @VWTR
       LI 0,>0200
       BLWP @VWTR
       LI 0,>030E
       BLWP @VWTR
       LI 0,>0401
       BLWP @VWTR
       LI 0,>0506
       BLWP @VWTR
       LI 0,>3700
       LI 1,DSRBUF
       LI 2,>900
       BLWP @VMBW
#endasm
}
 
drmaze(lev) int lev;
{ int level;
clear();
level=4;
if (lev<8) level=3;
if (lev<5) level=2;
if (lev<3) level=1;
switch(level) {
case 1:say( 3,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       say( 4,3,"bbbbb                  bbbbb");
       say( 5,3,"bbbbb bbbbb bbb bbbbbb bbbbb");
       say( 6,3,"b           bbb            b");
       say( 7,3,"b b bbbb bbbbbbbbb bbbbb b b");
       say( 8,3,"b   bbbb bbbbbbbbb bbbbb   b");
       say( 9,3,"b bbb       bbb        bbb b");
       say(10,3,"b     bbbbb bbb bbbbbb     b");
       say(11,3,"b bbb b   b     b    b bbb b");
       say(12,3,"b     b b bbb bbb bb b     b");
       say(13,3,"b bbb   b         bb   bbb b");
       say(14,3,"b b   bbbbb bbb bbbbbb   b b");
       say(15,3,"b   b b   b     b    b b b b");
       say(16,3,"bbb b   b   bbb   bb   b   b");
       say(17,3,"bbb bb bbb bbbbb bbbb bbbbbb");
       say(18,3,"b                          b");
       say(19,3,"b bb bbbb bbbbbbb bbbb bbb b");
       say(20,3,"b       b    b    b        b");
       say(21,3,"b bbbbb bbbb b bbbb bbbbbb b");
       say(22,3,"b                          b");
       say(23,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       break;
case 2:say( 3,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       say( 4,3,"b                      b   b");
       say( 5,3,"b bb bbbbbb bbbbb bbb bb b b");
       say( 6,3,"b bb   b  b  bbbb b b bb b b");
       say( 7,3,"b bbbb   bbb    b        b b");
       say( 8,3,"b b b  b  b  bb bbbb bbbbb b");
       say( 9,3,"b b   bbb   bbb bbb      b b");
       say(10,3,"b b b  b  b  b  bb  bb b b b");
       say(11,3,"b b bb   bbb   bb  bbb b b b");
       say(12,3,"b      b  b  b  b bbbb b b b");
       say(13,3,"b bbb bbb   bbb b      b b b");
       say(14,3,"b bb   b  b  bb b b bb b bbb");
       say(15,3,"b b  b   bbb      b bb b b b");
       say(16,3,"b b bbbb bb  b bb b    b b b");
       say(17,3,"b   bbb     bb bb b bbbb   b");
       say(18,3,"b b     bbb bb bb b b  b b b");
       say(19,3,"b b bbb  b        b bb b b b");
       say(20,3,"b b b bb   bb bbbbb bb b b b");
       say(21,3,"b b   bbbbbb   bbbb    b b b");
       say(22,3,"b   b        b      bb     b");
       say(23,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       break;
case 3:say( 3,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       say( 4,3,"b              b           b");
       say( 5,3,"b bbbbb bbbbb bbbbbbbbb bb b");
       say( 6,3,"b bbb   b   b    b bbbb bb b");
       say( 7,3,"b b bbb   b   bb   b     b b");
       say( 8,3,"b    bb bbbbb bbbb b bbb b b");
       say( 9,3,"b bb      b      b   b b b b");
       say(10,3,"b bbb bbb   b bb b bbb b b b");
       say(11,3,"b b   bbbb bb bbbb  bb b   b");
       say(12,3,"b b bbb    bb    bb  b   b b");
       say(13,3,"b bbb   bb bbb b  bb   b b b");
       say(14,3,"b b   bbb  bbb bb    bbb b b");
       say(15,3,"b   b   bbbb   bbbbb b b b b");
       say(16,3,"b bbbbb bb   bbbbb   b   b b");
       say(17,3,"b bbb   bb b   b   bbbbb b b");
       say(18,3,"b bb  b    b b   bbbbbbb b b");
       say(19,3,"b bb bb bbbbbbbbbbb      b b");
       say(20,3,"b bb bb             bb b b b");
       say(21,3,"b bb bbb bbbbbbbbbbbb  b b b");
       say(22,3,"b                     bb b b");
       say(23,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       break;
case 4:say( 3,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       say( 4,3,"b   b bb   b b  b          b");
       say( 5,3,"b b b bb bbb   bb b bb b b b");
       say( 6,3,"b b b b    b b bb bbbbbbbb b");
       say( 7,3,"b b     bb   b  b    b   b b");
       say( 8,3,"b b bbbbbb b b bbb bbb b   b");
       say( 9,3,"b b        b b     b   b b b");
       say(10,3,"b b bbb b bb bbbbb   b b b b");
       say(11,3,"b bbb   b  b bbbb  b b b b b");
       say(12,3,"b     b bb b bbbbb bbbbbbb b");
       say(13,3,"bbbbb b b  bbbbb        bb b");
       say(14,3,"b   b b b bb b   bbbbbb  b b");
       say(15,3,"b b b b b  b b bbb    bb b b");
       say(16,3,"b b b b bb b bbb   bb    b b");
       say(17,3,"b b b b bb   b   bbbbbb bb b");
       say(18,3,"b bbb b bbbb bbbbbbbbbb bb b");
       say(19,3,"b bb  b bb   b b bbbb b bb b");
       say(20,3,"b b  bb    b             b b");
       say(21,3,"b bbbbbbbbbb bbbbbbb bbb b b");
       say(22,3,"b            b       b     b");
       say(23,3,"bbbbbbbbbbbbbbbbbbbbbbbbbbbb");
       break; }
}
endlev()
{      clear();
       say(1,1,"YOU FINISHED LEVEL");
       say(2,1,"WITHOUT GETTING CAUGHT");
       hchar(1,20,l+47,1);
       qw=0;
       a=1;
       while (a<l+1)
            qw=qw+(a*a++);
       say(4,1,"YOU HAVE KILLED");
       say(5,1,"PEOPLE SO FAR!");
       nsay(4,17,qw);
       qw=0;
       while (qw!=18)
            qw=key(1,&x);
       l++;
       if (l==11)
       {    clear();
            say(1,1,"CONGRADULATIONS!");
            say(2,1,"YOU ARE NOW A FULLY");
            say(3,1,"QUALIFIED MASS");
            say(4,1,"MURDERER!");
            flag=2;
            qw=0;
            while (qw!=18)
              qw=key(1,&x);
       }
}
 
gamovr()
{      clear();
       say(1,3,">>>>>>>> GAME  OVER <<<<<<<<");
       say(3,3,"YOUR RATING:");
       switch (l) {
       case 1: say(3,16,"NOVICE"); break;
       case 2: say(3,16,"BEGINNER"); break;
       case 3: say(3,16,"MURDERER"); break;
       case 4: say(3,16,"A BLADE"); break;
       case 5: say(3,16,"QUICK AND SMART"); break;
       case 6: say(3,16,"PRETTY GOOD"); break;
       case 7: say(3,16,"COP TRICKER"); break;
       case 8: say(3,16,"PUBLIC ENEMY #1"); break;
       case 9: say(3,16,"ALMOST THERE"); break;
       case 10:say(3,16,"MASS MURDERER"); break; }
       say(6,3,"PRESS FIRE BUTTON TO REPLAY");
       qw=0;
       while (qw!=18)
            qw=key(1,&x);
}
smart()
{      if ((crd[a]!=0)|(cr[a]==r))
       {    qw=gchar(cr[a],cc[a]+sgn(c-cc[a]));
            if (qw!=98)
            {  ccd[a]=sgn(c-cc[a]);
               crd[a]=0;
            }
       }
       else
       {    qw=gchar(cr[a]+sgn(r-cr[a]),cc[a]);
            if (qw!=98)
            {  ccd[a]=0;
               crd[a]=sgn(r-cr[a]);
            }
       }
}
sgn(num) int num;
{      int z;
       z=0;
       if (num>0)
            z=1;
       if (num<0)
            z=-1;
       return z;
}
 
say(r,c,st) int r,c; char st[];
{      int a;
 
       a=0;
       while (st[a]!=0)
            hchar(r,c+a,st[a++],1);
}
 
nsay(r,c,n) int r,c,n;
{      int x1,a;
 
       a=n;
       x1=n/100;
       hchar(r,c,x1+48,1);
       a=a-x1*100;
       x1=a/10;
       hchar(r,c+1,x1+48,1);
       a=a-x1*10;
       hchar(r,c+2,a+48,1);
}
 
delay(t) int t;
{      int a;
 
       a=t*10;
       while (a>0)
            a--;
}
 
sound(f,v) int f,v;
{      int x1,x2;
 
       f=f/10;
       x1=11186/f;
       x2=x1&15;
       x1=x1-x2;
       x1=x1/16;
       x2=x2|128;
       x2=x2*256;
       x2=x2|x1;
       x1=144;
       v=v/2;
       x1=x1+v;
       xn1=x2;
       xn2=x1*256;
#asm
       MOV @XN1,@>8400
       LI 0,10
ZXCVBN DEC 0
       JNE ZXCVBN
       MOVB @XN2,@>8400
#endasm
}
 
inital()
{
       a=1;
       while (a<l*l+1)
       {    pr[a]=rnd(20)+3;
            pc[a]=rnd(28)+3;
            qw=gchar(pr[a],pc[a]);
            if (qw!=98)
            {  hchar(pr[a],pc[a],99,1);
               prd[a]=0;
               pcd[a]=0;
               while ((prd[a]==0)&(pcd[a]==0))
               {   prd[a]=rnd(3)-1;
                   pcd[a]=rnd(3)-1;
               }
               a++;
            }
       }
       pl=l*l;
       flag=0;
       st=30;
       ec=32;
       a=1;
       while (a<6)
       {    cr[a]=rnd(20)+3;
            cc[a]=rnd(28)+3;
            qw=gchar(cr[a],cc[a]);
            if (qw!=98)
            {  hchar(cr[a],cc[a],100,1);
               crd[a]=0;
               ccd[a]=0;
               while ((crd[a]==0)&(ccd[a]==0))
               {   crd[a]=rnd(3)-1;
                   ccd[a]=rnd(3)-1;
               }
               a++;
            }
       }
       qw=0;
       while (qw!=32)
       {    r=rnd(20)+3;
            c=rnd(28)+3;
            qw=gchar(r,c);
       }
       a=1;
       while (a<6)
       {    hchar(r,c,32,1);
            sound(220,0);
            delay(200);
            hchar(r,c,97,1);
            sound(550,0);
            delay(200);
            a++;
       }
}
define()
{      sound(110,30);
       title();
       st=30;
       ec=32;
       pn=1;
       flag=0;
       grf1();
       randomize();
       screen(2);
       a=4;
       while (a<21)
            color(a++,16,2);
       chrdef(97,"183C187E18182466");
       chrdef(98,"FFFFFFFFFFFFFFFF");
       chrdef(99,"1010385410102844");
       chrdef(100,"123A123C50102828");
       chrdef(101,"000000000018346A");
       l=1;
       flag=0;
}
 
player()
{
       a=joyst(1,&x,&y);
       if (ec==98)
            ec=32;
       if (x!=0)
       {    hchar(r,c,ec,1);
            x=x/4;
            c=c+x;
            qw=gchar(r,c);
            if (qw==98)
               c=c-x;
            ec=qw;
            if (ec!=101)
              ec=32;
            hchar(r,c,97,1);
       }
       if ((y!=0)&(x==0))
       {    hchar(r,c,ec,1);
            y=y/4;
            r=r-y;
            qw=gchar(r,c);
            if (qw==98)
               r=r+y;
            hchar(r,c,97,1);
            ec=qw;
       }
       if (qw==99)
       {    ec=101;
            a=0;
            while (a<31)
            { sound(550-a*2,a);
              delay(30);
              a++;
            }
            pl--;
            if (pl==0)
              flag=1;
            pr[pl+1]=0;
       }
       else
       {    if ((qw==100)&(st==0))
              flag=2;
       }
}
 
cop()
{
            sound(550,st);
            delay(50);
            sound(550,30);
            a=pn;
            if (st==0)
              smart();
            hchar(cr[a],cc[a],32,1);
            cr[a]=cr[a]+crd[a];
            cc[a]=cc[a]+ccd[a];
            qw=gchar(cr[a],cc[a]);
            if (qw==98)
            {  cr[a]=cr[a]-crd[a];
               cc[a]=cc[a]-ccd[a];
               hchar(cr[a],cc[a],100,1);
               crd[a]=0;
               ccd[a]=0;
               while ((crd[a]==0)&(ccd[a]==0))
               {  crd[a]=rnd(3)-1;
                  ccd[a]=rnd(3)-1;
               }
               if (crd[a]!=0)
                  ccd[a]=0;
            }
            else
            {  hchar(cr[a],cc[a],100,1);
               if ((qw==97)&(st==0))
                 flag=2;
               if (qw==101)
                 st=0;
            }
            pn=pn+1;
            if (pn==6)
               pn=1;
}
 
victim()
{
            n=rnd(pl)+1;
            if (pr[n]!=0)
            {  pe=32;
               qw=gchar(pr[n],pc[n]);
               if (qw==101)
                 pe=qw;
               hchar(pr[n],pc[n],pe,1);
               pr[n]=pr[n]+prd[n];
               pc[n]=pc[n]+pcd[n];
               qw=gchar(pr[n],pc[n]);
               if (qw==98)
               {  pc[n]=pc[n]-pcd[n];
                  pr[n]=pr[n]-prd[n];
                  hchar(pr[n],pc[n],99,1);
                  pcd[n]=0;
                  prd[n]=0;
                  while ((pcd[n]==0)&(prd[n]==0))
                  {      pcd[n]=rnd(3)-1;
                         prd[n]=rnd(3)-1;
                  }
               }
               else
                  hchar(pr[n],pc[n],99,1);
            }
}

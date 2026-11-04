
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_007a1d10(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_100c [1440];
  undefined1 auStack_a6c [2652];
  undefined4 uStack_10;
  
  iVar1 = param_3;
  uStack_10 = 0x7a1d1f;
  FUN_007a6d00(param_1,auStack_100c,0x800,param_2,param_3);
  FUN_007a72f0(auStack_a6c,auStack_100c,0x530,0x26c,&param_3,iVar1);
  return 0x2d0 - param_3;
}


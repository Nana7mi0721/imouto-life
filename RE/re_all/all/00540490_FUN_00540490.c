
undefined4
FUN_00540490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_800 [2048];
  
  FUN_00530d80();
  iVar2 = FUN_0052f1d0(DAT_00a4bca8);
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  FUN_00579b50(iVar2,0,DAT_00aba24c,iVar1,local_800,0x800,param_4,&param_5);
  uVar3 = FUN_00540340(param_1,param_2,local_800,param_3,0xfffffffe,0,0);
  return uVar3;
}


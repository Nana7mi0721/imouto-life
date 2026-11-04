
undefined4 FUN_0057bed0(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_400 [1024];
  
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  iVar1 = DAT_00aba250;
  if (DAT_00aba24c == 0) {
    FUN_0057a980();
  }
  FUN_00579b50(0x4b0,1,DAT_00aba24c,iVar1,local_400,0x200,param_1,&param_2);
  uVar2 = (*DAT_00aba0cc)();
  FUN_0056bca0(&DAT_007d825c,local_400,uVar2);
  return 0xffffffff;
}


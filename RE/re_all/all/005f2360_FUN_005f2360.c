
undefined4 __fastcall FUN_005f2360(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  undefined4 local_4;
  
  if (DAT_00f203b0 != 0) {
    iVar1 = FUN_00570e30(&DAT_00f22c80,0x7ffd,param_2,&local_8,&local_4);
    if (-1 < iVar1) {
      iVar1 = FUN_0056fda0(&DAT_00f22c80);
      uVar2 = FUN_0051c490(param_3,iVar1 + local_8,local_4,0,0,0);
      return uVar2;
    }
  }
  return 0xffffffff;
}


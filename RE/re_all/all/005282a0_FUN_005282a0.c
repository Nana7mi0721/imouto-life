
int FUN_005282a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined1 local_78 [108];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((DAT_00a21078 == 0) && (DAT_00a238d0 == 0)) {
    FUN_0050e770();
  }
  iVar1 = FUN_005809a0(1,param_4,0xffffffff);
  if (iVar1 != -1) {
    FUN_005193b0(local_78);
    local_8 = DAT_00a37f4c;
    local_c = DAT_00a37f54;
    local_4 = DAT_00a37f48;
    iVar2 = FUN_005245d0(local_78,0,iVar1,param_1,param_2,param_3,0);
    if (param_4 != 0) {
      FUN_00580f70(iVar1);
    }
    if (-1 < iVar2) {
      return iVar1;
    }
    FUN_00580b80(iVar1);
  }
  return -1;
}


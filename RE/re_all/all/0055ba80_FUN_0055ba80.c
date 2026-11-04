
undefined4 FUN_0055ba80(undefined4 param_1,int *param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = thunk_FUN_00572540(param_1,0,1,0);
  if (iVar1 == 0) {
    if (param_4 != 0) {
      FUN_0056bc50(L"File Open Error : %s",param_1);
      return 0xffffffff;
    }
  }
  else {
    FUN_0052c610(iVar1,0,0,2);
    uVar2 = thunk_FUN_00571dd0(iVar1);
    FUN_0052c610(iVar1,0,0,0);
    iVar3 = FUN_0056e030(uVar2,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x40aa);
    if (iVar3 != 0) {
      thunk_FUN_00571e60(iVar3,uVar2,1,iVar1);
      thunk_FUN_00571d20(iVar1);
      *param_2 = iVar3;
      *param_3 = uVar2;
      return 0;
    }
    FUN_0056bc50(L"File Load : Memory Alloc Error : %s",param_1);
    thunk_FUN_00571d20(iVar1);
  }
  return 0xffffffff;
}


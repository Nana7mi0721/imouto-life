
undefined4 FUN_005971c0(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00597160(param_1);
  iVar2 = FUN_0056e030(uVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxSoundConvert.cpp",0x15f);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  FUN_00596ef0(param_1,0);
  if ((*(int *)(param_1 + 8) == 0) && (*(short *)(param_1 + 0x5e) == 1)) {
    (**(code **)(param_1 + 0x14))(iVar2,uVar1,1,*(undefined4 *)(param_1 + 0x24));
  }
  else {
    uVar1 = FUN_00596f70(param_1,iVar2,uVar1);
  }
  *param_2 = *(undefined4 *)(param_1 + 0x38);
  param_2[1] = *(undefined4 *)(param_1 + 0x3c);
  param_2[2] = *(undefined4 *)(param_1 + 0x40);
  param_2[3] = *(undefined4 *)(param_1 + 0x44);
  *(undefined2 *)(param_2 + 4) = *(undefined2 *)(param_1 + 0x48);
  *param_3 = iVar2;
  *param_4 = uVar1;
  return 0;
}


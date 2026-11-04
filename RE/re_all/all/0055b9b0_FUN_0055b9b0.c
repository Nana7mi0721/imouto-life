
undefined4
FUN_0055b9b0(int *param_1,int *param_2,undefined4 param_3,int param_4,undefined4 param_5,int param_6
            )

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_4 + 0x1c + param_6;
  iVar2 = FUN_0056e030(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x4078);
  if (iVar2 == 0) {
    FUN_0056bb10(&DAT_007d62d0);
    return 0xffffffff;
  }
  FUN_0056d420(iVar2,&DAT_007d6168,4);
  *(int *)(iVar2 + 4) = iVar1 + -8;
  FUN_0056d420(iVar2 + 8,&DAT_007d6160,4);
  FUN_0056d420(iVar2 + 0xc,&DAT_007d6158,4);
  *(int *)(iVar2 + 0x10) = param_4;
  FUN_0056d420(iVar2 + 0x14,param_3,param_4);
  param_4 = iVar2 + 0x14 + param_4;
  FUN_0056d420(param_4,&DAT_007d6150,4);
  *(int *)(param_4 + 4) = param_6;
  FUN_0056d420(param_4 + 8,param_5,param_6);
  *param_1 = iVar2;
  *param_2 = iVar1;
  return 0;
}


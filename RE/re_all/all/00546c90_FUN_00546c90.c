
undefined4 FUN_00546c90(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  FUN_00544500(param_3);
  iVar1 = (uint)*(byte *)(param_3 + 4) * param_1 + 3;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * 4;
  *(int *)(param_3 + 0x430) = iVar1;
  *(int *)(param_3 + 0x428) = param_1;
  *(int *)(param_3 + 0x42c) = param_2;
  iVar1 = FUN_0056e030(iVar1 * param_2,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                       0x14a2);
  *(int *)(param_3 + 0x434) = iVar1;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  *(undefined4 *)(param_3 + 0x438) = 0;
  *(undefined4 *)(param_3 + 0x43c) = 0;
  return 0;
}


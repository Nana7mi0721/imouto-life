
undefined4 FUN_00541fe0(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_4;
  for (iVar1 = 0x10a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_3;
    param_3 = param_3 + 1;
    puVar2 = puVar2 + 1;
  }
  iVar1 = (uint)*(byte *)(param_4 + 1) * param_1 + 3;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) * 4;
  param_4[0x10c] = iVar1;
  param_4[0x10a] = param_1;
  param_4[0x10b] = param_2;
  iVar1 = FUN_0056e030(iVar1 * param_2,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                       0x153b);
  param_4[0x10d] = iVar1;
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  param_4[0x10e] = 0;
  param_4[0x10f] = 0;
  return 0;
}


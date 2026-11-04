
undefined4 FUN_007989b0(int *param_1,uint param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  iVar5 = param_3;
  iVar2 = param_2;
  if (((((param_2 != 48000) && (param_2 != 24000)) && (param_2 != 16000)) &&
      ((param_2 != 12000 && (param_2 != 8000)))) || ((param_3 != 1 && (param_3 != 2)))) {
    return 0xffffffff;
  }
  uVar3 = FUN_00798960(param_3);
  piVar7 = param_1;
  for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)piVar7 = 0;
    piVar7 = (int *)((int)piVar7 + 1);
  }
  iVar4 = FUN_00799c20(&param_2);
  if (iVar4 != 0) {
    return 0xfffffffd;
  }
  param_1[1] = 0x58;
  param_1[2] = iVar5;
  param_1[0xb] = iVar5;
  param_2 = param_2 + 3 & 0xfffffffc;
  *param_1 = param_2 + 0x58;
  puVar1 = (undefined1 *)(param_2 + 0x58 + (int)param_1);
  param_1[3] = iVar2;
  param_1[6] = iVar2;
  param_1[4] = iVar5;
  iVar4 = FUN_00799c30(param_1 + 0x16);
  if (iVar4 != 0) {
    return 0xfffffffd;
  }
  iVar5 = FUN_007a0320(puVar1,iVar2,iVar5);
  if (iVar5 == 0) {
    FUN_007a1d70(puVar1,0x2720,0);
    param_1[0xe] = 0;
    param_1[0x15] = 0;
    param_1[0xf] = iVar2 / 400;
    return 0;
  }
  return 0xfffffffd;
}


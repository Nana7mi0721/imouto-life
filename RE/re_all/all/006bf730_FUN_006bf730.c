
void FUN_006bf730(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  
  iVar10 = param_2[1] * 0xfb15;
  iVar5 = param_2[1] * 0x31f1;
  sVar9 = (short)((uint)(*param_2 * 0xb505) >> 0x10);
  sVar4 = (short)((uint)(param_2[2] * 0x61f8) >> 0x10);
  sVar2 = sVar9 + sVar4;
  sVar4 = sVar9 - sVar4;
  sVar1 = (short)((uint)(param_2[2] * 0xec83) >> 0x10);
  sVar7 = sVar1 + sVar9;
  sVar9 = sVar9 - sVar1;
  sVar3 = (short)((uint)((iVar10 >> 0x10) * 0xb505) >> 0x10);
  sVar6 = (short)((uint)((iVar5 >> 0x10) * 0xb505) >> 0x10);
  sVar1 = sVar3 + sVar6;
  sVar3 = sVar3 - sVar6;
  sVar6 = (short)((uint)iVar10 >> 0x10);
  *param_1 = sVar6 + sVar7;
  param_1[8] = sVar1 + sVar2;
  param_1[0x10] = sVar3 + sVar4;
  sVar8 = (short)((uint)iVar5 >> 0x10);
  param_1[0x18] = sVar8 + sVar9;
  param_1[0x28] = sVar4 - sVar3;
  param_1[0x20] = sVar9 - sVar8;
  param_1[0x30] = sVar2 - sVar1;
  param_1[0x38] = sVar7 - sVar6;
  return;
}


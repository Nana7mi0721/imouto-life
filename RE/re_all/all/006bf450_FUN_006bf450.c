
void FUN_006bf450(short *param_1,short *param_2)

{
  int iVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  
  iVar7 = param_2[1] * 0xfb15;
  iVar1 = param_2[1] * 0x31f1;
  sVar2 = (short)((uint)iVar7 >> 0x10);
  sVar3 = (short)((uint)(*param_2 * 0xb505) >> 0x10);
  sVar5 = (short)((uint)((iVar7 >> 0x10) * 0xb505) >> 0x10);
  sVar6 = (short)((uint)((iVar1 >> 0x10) * 0xb505) >> 0x10);
  sVar4 = sVar5 + sVar6;
  sVar5 = sVar5 - sVar6;
  *param_1 = sVar2 + sVar3;
  param_1[8] = sVar4 + sVar3;
  param_1[0x10] = sVar5 + sVar3;
  sVar6 = (short)((uint)iVar1 >> 0x10);
  param_1[0x18] = sVar6 + sVar3;
  param_1[0x20] = sVar3 - sVar6;
  param_1[0x28] = sVar3 - sVar5;
  param_1[0x30] = sVar3 - sVar4;
  param_1[0x38] = sVar3 - sVar2;
  return;
}


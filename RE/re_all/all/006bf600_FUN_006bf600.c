
void FUN_006bf600(short *param_1,short *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  
  sVar11 = (short)((uint)(param_2[3] * 0x8e3a) >> 0x10);
  sVar10 = (short)((uint)(param_2[1] * 0x31f1) >> 0x10);
  sVar3 = sVar10 - sVar11;
  sVar8 = (short)((uint)(param_2[1] * 0xfb15) >> 0x10);
  sVar9 = (short)((uint)(param_2[3] * 0xd4db) >> 0x10);
  sVar5 = sVar8 + sVar9;
  sVar4 = (short)((uint)(*param_2 * 0xb505) >> 0x10);
  sVar7 = (short)((uint)(param_2[2] * 0x61f8) >> 0x10);
  sVar2 = sVar4 + sVar7;
  sVar7 = sVar4 - sVar7;
  sVar1 = (short)((uint)(param_2[2] * 0xec83) >> 0x10);
  sVar6 = sVar1 + sVar4;
  sVar4 = sVar4 - sVar1;
  sVar8 = (short)((uint)((short)(sVar8 - sVar9) * 0xb505) >> 0x10);
  sVar9 = (short)((uint)((short)(sVar10 + sVar11) * 0xb505) >> 0x10);
  sVar1 = sVar8 + sVar9;
  sVar8 = sVar8 - sVar9;
  *param_1 = sVar5 + sVar6;
  param_1[8] = sVar1 + sVar2;
  param_1[0x10] = sVar7 + sVar8;
  param_1[0x18] = sVar3 + sVar4;
  param_1[0x28] = sVar7 - sVar8;
  param_1[0x20] = sVar4 - sVar3;
  param_1[0x38] = sVar6 - sVar5;
  param_1[0x30] = sVar2 - sVar1;
  return;
}


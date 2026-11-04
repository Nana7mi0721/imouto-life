
void FUN_006bf8e0(short *param_1,short *param_2)

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
  short sVar12;
  
  sVar8 = (short)((uint)(param_2[2] * 0x61f8) >> 0x10) -
          (short)((uint)(param_2[6] * 0xec83) >> 0x10);
  sVar7 = (short)((uint)(param_2[2] * 0xec83) >> 0x10) +
          (short)((uint)(param_2[6] * 0x61f8) >> 0x10);
  sVar12 = (short)((uint)(param_2[1] * 0x31f1) >> 0x10) -
           (short)((uint)(param_2[7] * 0xfb15) >> 0x10);
  sVar11 = (short)((uint)(param_2[5] * 0xd4db) >> 0x10) -
           (short)((uint)(param_2[3] * 0x8e3a) >> 0x10);
  sVar10 = (short)((uint)(param_2[5] * 0x8e3a) >> 0x10) +
           (short)((uint)(param_2[3] * 0xd4db) >> 0x10);
  sVar9 = (short)((uint)(param_2[7] * 0x31f1) >> 0x10) +
          (short)((uint)(param_2[1] * 0xfb15) >> 0x10);
  sVar4 = sVar11 + sVar12;
  sVar1 = sVar9 + sVar10;
  sVar5 = (short)((uint)((short)(*param_2 + param_2[4]) * 0xb505) >> 0x10);
  sVar2 = sVar7 + sVar5;
  sVar5 = sVar5 - sVar7;
  sVar3 = (short)((uint)((short)(*param_2 - param_2[4]) * 0xb505) >> 0x10);
  sVar6 = sVar8 + sVar3;
  sVar3 = sVar3 - sVar8;
  sVar7 = (short)((uint)((short)(sVar9 - sVar10) * 0xb505) >> 0x10);
  sVar9 = (short)((uint)((short)(sVar12 - sVar11) * 0xb505) >> 0x10);
  sVar8 = sVar7 + sVar9;
  sVar7 = sVar7 - sVar9;
  *param_1 = sVar1 + sVar2;
  param_1[8] = sVar8 + sVar6;
  param_1[0x10] = sVar7 + sVar3;
  param_1[0x30] = sVar6 - sVar8;
  param_1[0x18] = sVar4 + sVar5;
  param_1[0x28] = sVar3 - sVar7;
  param_1[0x20] = sVar5 - sVar4;
  param_1[0x38] = sVar2 - sVar1;
  return;
}


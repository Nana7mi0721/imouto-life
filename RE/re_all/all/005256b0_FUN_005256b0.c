
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_005256b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,double param_7,
            double param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int unaff_ESI;
  bool bVar6;
  ushort in_FPUControlWord;
  float10 fVar7;
  float local_11c;
  float local_118;
  float local_114;
  float local_110 [2];
  ushort local_108;
  ushort local_104;
  float local_fc;
  ushort local_f8;
  float local_ec;
  ushort local_e8;
  ushort local_e0;
  int local_dc;
  ushort local_d8;
  int local_d0;
  ushort local_cc;
  ushort local_c0;
  int local_bc;
  int local_b8;
  ushort local_b4;
  ushort local_b0;
  uint local_a4;
  int local_a0;
  float local_9c;
  float local_98;
  int local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  int local_7c;
  float local_78;
  ushort local_74;
  float local_70;
  ushort local_6c;
  ushort local_5c;
  float local_58;
  float local_54;
  float local_50;
  int local_4c;
  int local_48;
  float local_44;
  undefined8 local_40;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  float local_1c;
  int local_18;
  int local_14;
  double local_10;
  
  iVar2 = param_4;
  iVar1 = param_3;
  local_80 = (float)param_8;
  local_9c = (float)param_7;
  if (local_9c <= 0.0) {
    param_7 = _DAT_00804678;
  }
  if (param_3 < param_1) {
    param_3 = param_1;
    param_1 = iVar1;
  }
  if (param_4 < param_2) {
    param_4 = param_2;
    param_2 = iVar2;
  }
  iVar1 = *(int *)(unaff_ESI + 0x60);
  iVar2 = *(int *)(unaff_ESI + 100);
  FUN_0056d4d0(local_80,&local_118,&local_11c);
  local_50 = local_9c * (float)*(int *)(unaff_ESI + 0x60) * local_11c;
  local_44 = local_9c * local_118 * (float)*(int *)(unaff_ESI + 0x60);
  local_fc = local_80 + (float)_DAT_007d56b8;
  FUN_0056d4d0(local_fc,&local_114,local_110);
  local_80 = local_9c * (float)*(int *)(unaff_ESI + 100) * local_110[0];
  local_58 = local_9c * local_114 * (float)*(int *)(unaff_ESI + 100);
  local_8c = (float)(param_3 - param_1);
  local_90 = (float)(param_4 - param_2);
  local_fc = local_8c * local_8c + local_90 * local_90;
  fVar7 = (float10)FUN_0056d670(local_fc);
  local_a4 = *(int *)(unaff_ESI + 100);
  if (*(int *)(unaff_ESI + 0x60) <= *(int *)(unaff_ESI + 100)) {
    local_a4 = *(int *)(unaff_ESI + 0x60);
  }
  local_40 = (double)(fVar7 / ((float10)(int)local_a4 * (float10)param_7) + (float10)_DAT_00829868);
  local_d8 = in_FPUControlWord | 0xc00;
  local_a4 = (uint)ROUND(local_40);
  uVar5 = local_a4 & 0x80000001;
  bVar6 = uVar5 == 0;
  if ((int)uVar5 < 0) {
    bVar6 = (uVar5 - 1 | 0xfffffffe) == 0xffffffff;
  }
  if (bVar6) {
    local_a4 = local_a4 + 1;
  }
  local_2c = DAT_00a38198;
  local_30 = DAT_00a38194;
  local_28 = DAT_00a3819c;
  local_24 = DAT_00a381a0;
  FUN_005217e0(param_1,param_2,param_3,param_4);
  fVar4 = local_9c * (float)(-((int)(*(int *)(unaff_ESI + 0x60) * local_a4) / 2) - param_5 % iVar1);
  fVar3 = local_9c * (float)(-((int)(*(int *)(unaff_ESI + 100) * local_a4) / 2) - param_6 % iVar2);
  local_54 = local_11c * fVar4 - local_118 * fVar3;
  local_70 = (float)param_2 + local_90 * (float)_DAT_00804a60 +
             fVar4 * local_118 + local_11c * fVar3;
  local_fc = (float)_DAT_00804a60 * local_8c + (float)param_1;
  local_78 = local_fc + local_54;
  if (0 < (int)local_a4) {
    local_fc = (float)local_a4;
    local_54 = (float)local_a4;
    local_98 = local_78;
    local_88 = local_70;
    while( true ) {
      do {
        if (param_8 == 0.0) {
          if (param_7 == 0.0) {
            local_b0 = in_FPUControlWord | 0xc00;
            local_8c = (float)(int)ROUND(local_88);
            local_6c = in_FPUControlWord | 0xc00;
            local_48 = (int)ROUND(local_98);
            FUN_006c8cc0(DAT_00a37e58,unaff_ESI + 0x88,local_48,local_8c,param_9,DAT_00a37e5c);
          }
          else {
            local_e0 = in_FPUControlWord | 0xc00;
            local_94 = (int)ROUND(local_58 + local_88);
            local_ec = local_98 + local_50;
            local_c0 = in_FPUControlWord | 0xc00;
            local_7c = (int)ROUND(local_ec);
            local_b4 = in_FPUControlWord | 0xc00;
            local_90 = (float)(int)ROUND(local_88);
            local_74 = in_FPUControlWord | 0xc00;
            local_38 = (int)ROUND(local_98);
            local_20 = local_38;
            local_1c = local_90;
            local_18 = local_7c;
            local_14 = local_94;
            FUN_006ea010(DAT_00a37e58,unaff_ESI + 0x88,&local_20,param_9,DAT_00a37e5c);
          }
        }
        else {
          fVar3 = local_88 + local_44;
          local_dc = (int)ROUND(fVar3 + local_58);
          fVar4 = local_98 + local_50;
          local_10 = (double)fVar4;
          local_108 = in_FPUControlWord | 0xc00;
          local_d0 = (int)ROUND(fVar4 + local_80);
          local_104 = in_FPUControlWord | 0xc00;
          local_bc = (int)ROUND(local_88 + local_58);
          local_f8 = in_FPUControlWord | 0xc00;
          local_b8 = (int)ROUND(local_98 + local_80);
          local_e8 = in_FPUControlWord | 0xc00;
          local_a0 = (int)ROUND(fVar3);
          local_cc = in_FPUControlWord | 0xc00;
          local_ec = (float)(int)ROUND(fVar4);
          local_d8 = in_FPUControlWord | 0xc00;
          local_9c = (float)(int)ROUND(local_88);
          local_40 = (double)CONCAT44((int)((ulonglong)(double)fVar3 >> 0x20),local_9c);
          local_5c = in_FPUControlWord | 0xc00;
          local_4c = (int)ROUND(local_98);
          local_84 = local_ec;
          local_34 = local_a0;
          FUN_00515410(local_ec,local_a0,local_b8,local_bc,local_d0,local_dc);
        }
        local_54 = (float)((int)local_54 - 1);
        local_98 = local_98 + local_50;
        local_88 = local_44 + local_88;
      } while (local_54 != 0.0);
      local_fc = (float)((int)local_fc - 1);
      local_78 = local_78 + local_80;
      local_70 = local_58 + local_70;
      if (local_fc == 0.0) break;
      local_54 = (float)local_a4;
      local_98 = local_78;
      local_88 = local_70;
    }
    local_54 = 0.0;
    local_fc = 0.0;
  }
  FUN_005217e0(local_30,local_2c,local_28,local_24);
  return 0;
}


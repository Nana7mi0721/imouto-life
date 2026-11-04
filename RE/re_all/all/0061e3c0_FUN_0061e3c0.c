
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0061e3c0(int param_1,int *param_2,undefined1 *param_3)

{
  int *piVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float **ppfStack_210;
  undefined1 *puStack_20c;
  float fStack_208;
  undefined1 *puStack_204;
  float *apfStack_200 [4];
  undefined4 uStack_1e0;
  undefined4 uStack_1dc;
  undefined4 uStack_1d8;
  undefined4 uStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  undefined4 uStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined4 uStack_1b4;
  undefined4 uStack_1b0;
  undefined4 uStack_1ac;
  undefined4 uStack_1a8;
  undefined4 uStack_1a4;
  undefined1 auStack_1a0 [16];
  undefined1 auStack_190 [8];
  float fStack_188;
  float fStack_184;
  float fStack_180;
  undefined4 uStack_17c;
  float fStack_178;
  float fStack_174;
  float local_170;
  undefined4 uStack_16c;
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 local_160;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  undefined4 local_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined1 auStack_140 [16];
  undefined1 auStack_130 [8];
  float fStack_128;
  float fStack_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float fStack_110;
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [24];
  undefined1 local_f0 [16];
  undefined1 auStack_e0 [8];
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined1 local_b0 [32];
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_30 [48];
  
  iVar7 = *(int *)(param_1 + 4);
  iVar8 = *(int *)(iVar7 + 0xc0);
  apfStack_200[3] = (float *)(iVar7 + 4);
  apfStack_200[2] = (float *)0x61e3e5;
  FUN_005fc5f0();
  local_60 = *(undefined4 *)(iVar7 + 0x34);
  local_5c = *(undefined4 *)(iVar7 + 0x38);
  local_58 = *(undefined4 *)(iVar7 + 0x3c);
  local_54 = *(undefined4 *)(iVar7 + 0x40);
  iVar7 = *(int *)(param_1 + 4);
  apfStack_200[3] = (float *)(iVar7 + 0x44);
  apfStack_200[2] = (float *)0x61e422;
  FUN_005fc5f0();
  local_120 = *(float *)(iVar7 + 0x74);
  local_11c = *(float *)(iVar7 + 0x78);
  local_118 = *(float *)(iVar7 + 0x7c);
  local_114 = *(float *)(iVar7 + 0x80);
  iVar7 = (int)param_3 * 0x50 + *(int *)(iVar8 + 0x18);
  apfStack_200[2] = (float *)local_b0;
  apfStack_200[3] = (float *)(iVar7 + 0x30);
  apfStack_200[1] = (float *)0x61e477;
  puVar3 = (undefined4 *)FUN_005fc8d0();
  apfStack_200[2] = (float *)&local_90;
  apfStack_200[1] = (float *)local_30;
  apfStack_200[0] = (float *)0x61e48f;
  apfStack_200[3] = (float *)iVar7;
  apfStack_200[3] = (float *)FUN_005fc790();
  apfStack_200[2] = (float *)0x61e49f;
  FUN_005fc5f0();
  local_c0 = *puVar3;
  local_bc = puVar3[1];
  local_b8 = puVar3[2];
  local_b4 = puVar3[3];
  apfStack_200[3] = &local_170;
  apfStack_200[2] = (float *)&local_160;
  apfStack_200[1] = (float *)local_f0;
  apfStack_200[0] = (float *)0x61e4ec;
  (**(code **)(*param_2 + 4))();
  apfStack_200[0] = &local_11c;
  puStack_204 = auStack_10c;
  fStack_208 = (float)(*(int *)(param_1 + 8) + 4);
  puStack_20c = (undefined1 *)0x61e50e;
  (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0xc0) + 4))();
  bVar2 = true;
  if ((fStack_128 < fStack_178) || (fStack_188 < local_118)) {
    bVar2 = false;
  }
  if ((local_120 < local_170) || (fStack_180 < fStack_110)) {
    bVar2 = false;
  }
  if (((fStack_174 <= fStack_124) && (local_114 <= fStack_184)) && (bVar2)) {
    iVar7 = *(int *)(param_1 + 4);
    puStack_20c = auStack_108;
    ppfStack_210 = (float **)0x61e5b6;
    FUN_005fc5f0();
    *(undefined4 *)(iVar7 + 0x34) = uStack_d8;
    *(undefined4 *)(iVar7 + 0x38) = uStack_d4;
    puStack_20c = auStack_108;
    *(undefined4 *)(iVar7 + 0x3c) = uStack_d0;
    *(undefined4 *)(iVar7 + 0x40) = uStack_cc;
    iVar7 = *(int *)(param_1 + 4);
    ppfStack_210 = (float **)0x61e5f5;
    FUN_005fc5f0();
    *(undefined4 *)(iVar7 + 0x74) = uStack_d8;
    *(undefined4 *)(iVar7 + 0x78) = uStack_d4;
    *(undefined4 *)(iVar7 + 0x7c) = uStack_d0;
    *(undefined4 *)(iVar7 + 0x80) = uStack_cc;
    uStack_1bc = *(undefined4 *)(*(int *)(param_1 + 4) + 0xc0);
    *(int **)(*(int *)(param_1 + 4) + 0xc0) = param_2;
    if (*(int *)(*(int *)(param_1 + 0x18) + (int)param_3 * 4) == 0) {
      puStack_20c = *(undefined1 **)(param_1 + 0x1c);
      ppfStack_210 = *(float ***)(param_1 + 8);
      uVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 4))(*(undefined4 *)(param_1 + 4));
      *(undefined4 *)(*(int *)(param_1 + 0x18) + (int)param_3 * 4) = uVar4;
    }
    piVar1 = *(int **)(param_1 + 0x14);
    if (piVar1[0x22] == *(int *)(param_1 + 4)) {
      puStack_20c = param_3;
      ppfStack_210 = (float **)0xffffffff;
      (**(code **)(*piVar1 + 4))();
    }
    else {
      puStack_20c = param_3;
      ppfStack_210 = (float **)0xffffffff;
      (**(code **)(*piVar1 + 8))();
    }
    (**(code **)(**(int **)(*(int *)(param_1 + 0x18) + (int)param_3 * 4) + 4))
              (*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
               *(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
    piVar1 = *(int **)(*(int *)(param_1 + 0x10) + 0x14);
    if (piVar1 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar1 + 0x2c))();
      if ((uVar5 & 2) != 0) {
        piVar1 = *(int **)(*(int *)(param_1 + 0x10) + 0x14);
        ppfStack_210 = (float **)0x3f000000;
        uVar4 = FUN_005fc590(&uStack_d0,auStack_1a0,auStack_190,&ppfStack_210);
        FUN_0060fe40(&fStack_1d0,uVar4);
        ppfStack_210 = (float **)0x3f000000;
        uVar4 = FUN_0060f480(&uStack_d0,auStack_1a0,auStack_190,&ppfStack_210);
        FUN_0060fe40(auStack_e0,uVar4);
        ppfStack_210 = (float **)0x3f800000;
        fStack_208 = 1.0;
        puStack_20c = (undefined1 *)0x3f800000;
        FUN_005fc500(&puStack_20c,&fStack_208,&ppfStack_210);
        ppfStack_210 = apfStack_200;
        iVar7 = 0;
        do {
          iVar8 = 0;
          do {
            puStack_20c = (undefined1 *)((float)apfStack_200[2] * fStack_1c8);
            fStack_208 = (float)apfStack_200[1] * fStack_1cc;
            puStack_204 = (undefined1 *)(fStack_1d0 * (float)apfStack_200[0]);
            puVar3 = (undefined4 *)FUN_005fc500(&puStack_204,&fStack_208,&puStack_20c);
            uStack_1b0 = *puVar3;
            uStack_1ac = puVar3[1];
            uStack_1a8 = puVar3[2];
            uStack_1a4 = puVar3[3];
            FUN_00612f50(auStack_e0);
            apfStack_200[iVar8 % 3] = (float *)((float)apfStack_200[iVar8 % 3] * _DAT_007d5340);
            puStack_204 = (undefined1 *)((float)apfStack_200[2] * fStack_1c8);
            puStack_20c = (undefined1 *)((float)apfStack_200[1] * fStack_1cc);
            fStack_208 = fStack_1d0 * (float)apfStack_200[0];
            puVar3 = (undefined4 *)FUN_005fc500(&fStack_208,&puStack_20c,&puStack_204);
            uStack_1c0 = *puVar3;
            uStack_1bc = puVar3[1];
            uStack_1b8 = puVar3[2];
            uStack_1b4 = puVar3[3];
            FUN_00612f50(auStack_e0);
            (**(code **)(*piVar1 + 4))(&uStack_1b0,&uStack_1c0,apfStack_200 + 4);
            iVar8 = iVar8 + 1;
          } while (iVar8 < 3);
          uStack_1dc = 0xbf800000;
          uStack_1e0 = 0xbf800000;
          uStack_1d8 = 0xbf800000;
          piVar6 = (int *)FUN_005fc500(&uStack_1d8,&uStack_1e0,&uStack_1dc);
          apfStack_200[0] = (float *)*piVar6;
          apfStack_200[1] = (float *)piVar6[1];
          apfStack_200[2] = (float *)piVar6[2];
          apfStack_200[3] = (float *)piVar6[3];
          if (iVar7 < 3) {
            *ppfStack_210 = (float *)((float)*ppfStack_210 * _DAT_007d5340);
          }
          iVar7 = iVar7 + 1;
          ppfStack_210 = ppfStack_210 + 1;
        } while (iVar7 < 4);
        FUN_0061ddc0(auStack_130,auStack_140,apfStack_200 + 4);
      }
    }
    *(undefined4 *)(*(int *)(param_1 + 4) + 0xc0) = uStack_1d4;
    iVar7 = *(int *)(param_1 + 4);
    FUN_005fc5f0(&local_c0);
    *(undefined4 *)(iVar7 + 0x34) = local_90;
    *(undefined4 *)(iVar7 + 0x38) = uStack_8c;
    *(undefined4 *)(iVar7 + 0x3c) = uStack_88;
    *(undefined4 *)(iVar7 + 0x40) = uStack_84;
    iVar7 = *(int *)(param_1 + 4);
    *(float *)(iVar7 + 0x44) = fStack_180;
    *(undefined4 *)(iVar7 + 0x48) = uStack_17c;
    *(float *)(iVar7 + 0x4c) = fStack_178;
    *(float *)(iVar7 + 0x50) = fStack_174;
    *(float *)(iVar7 + 0x54) = local_170;
    *(undefined4 *)(iVar7 + 0x58) = uStack_16c;
    *(undefined4 *)(iVar7 + 0x5c) = uStack_168;
    *(undefined4 *)(iVar7 + 0x60) = uStack_164;
    *(undefined4 *)(iVar7 + 100) = local_160;
    *(undefined4 *)(iVar7 + 0x68) = uStack_15c;
    *(undefined4 *)(iVar7 + 0x6c) = uStack_158;
    *(undefined4 *)(iVar7 + 0x70) = uStack_154;
    *(undefined4 *)(iVar7 + 0x74) = local_150;
    *(undefined4 *)(iVar7 + 0x78) = uStack_14c;
    *(undefined4 *)(iVar7 + 0x7c) = uStack_148;
    *(undefined4 *)(iVar7 + 0x80) = uStack_144;
  }
  return;
}


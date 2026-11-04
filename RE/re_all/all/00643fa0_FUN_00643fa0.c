
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00643fa0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float *pfVar9;
  float *pfVar10;
  float *pfVar11;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  float local_2e4;
  float local_2e0;
  float local_2dc;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  undefined4 local_2a4;
  undefined1 local_2a0 [16];
  float local_290;
  float local_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_268 [2];
  float local_260;
  float local_25c;
  float local_258;
  float local_250;
  float local_24c;
  float local_248;
  undefined1 local_244 [4];
  undefined1 local_240 [16];
  undefined1 local_230 [16];
  undefined1 local_220 [16];
  undefined1 local_210 [48];
  float local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined1 local_1d0 [96];
  undefined1 local_170 [16];
  undefined1 local_160 [64];
  undefined1 local_120 [48];
  undefined1 local_f0 [16];
  undefined1 local_e0 [128];
  undefined1 local_60 [48];
  undefined1 local_30 [48];
  
  *(undefined4 *)(param_1 + 0x21c) = 0;
  *(undefined4 *)(param_1 + 0x218) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  *(undefined1 *)(param_1 + 0x232) = 0;
  if ((*(char *)(param_1 + 0x24c) != '\0') && (*(char *)(param_1 + 0x233) == '\0')) {
    local_2b0 = 0.0;
    local_2ac = 0.0;
    local_2a8 = 0.0;
    local_2a4 = 0;
    FUN_0061a1e0(param_1 + 0x250);
    local_1e0 = local_2b0;
    local_1dc = local_2ac;
    local_1d8 = local_2a8;
    local_1d4 = local_2a4;
    uVar2 = FUN_005fc8d0(local_2a0,param_1 + 0x180);
    uVar3 = FUN_005fc790(local_1d0,param_2,param_1 + 0x150,uVar2);
    FUN_005fcd10(uVar3,uVar2);
    uVar2 = FUN_005fc8d0(local_2a0,param_1 + 0x1c0);
    uVar3 = FUN_005fc790(local_1d0,param_3,param_1 + 400,uVar2);
    FUN_005fcd10(uVar3,uVar2);
    FUN_005fc6e0(local_1d0);
    uVar2 = FUN_005fc5c0(local_2a0,local_170);
    uVar2 = FUN_005fc730(local_240,local_1d0,uVar2);
    FUN_005fcd10(local_1d0,uVar2);
    uVar2 = FUN_005fc8d0(&local_270,&local_1e0);
    uVar3 = FUN_005fc790(local_30,local_160,local_210,uVar2);
    FUN_005fcd10(uVar3,uVar2);
    uVar2 = FUN_005fc8d0(&local_260,local_f0);
    uVar3 = FUN_005fc790(local_60,local_e0,local_120,uVar2);
    FUN_005fcd10(uVar3,uVar2);
    FUN_0061abb0(&local_2c0);
    local_2b0 = local_2c0;
    local_2ac = local_2bc;
    local_2a8 = local_2b8;
    *(float *)(param_1 + 0x1f0) = local_2c0;
    local_2a4 = 0;
    *(float *)(param_1 + 500) = local_2bc;
    *(float *)(param_1 + 0x1f8) = local_2b8;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    fVar6 = (float10)FUN_005fcc30((float *)(param_1 + 0x1f0));
    local_2e0 = (float)((float10)_DAT_00804108 / SQRT(fVar6));
    FUN_0061a860(&local_2e0);
    fVar6 = (float10)FUN_006c5580();
    *(float *)(param_1 + 0x21c) = (float)(fVar6 + fVar6);
    if (ABS(fVar6 + fVar6) < (float10)_DAT_00804520) {
      return;
    }
    *(undefined1 *)(param_1 + 0x232) = 1;
    return;
  }
  FUN_0061abb0(&local_2c0);
  local_2d8 = local_2bc;
  local_2dc = local_2c0;
  local_2d4 = local_2b8;
  local_2d0 = local_2b4;
  FUN_0061abb0(&local_2f0);
  local_2e0 = ((local_2e4 * local_2d0 - local_2dc * local_2f0) - local_2d8 * local_2ec) -
              local_2d4 * local_2e8;
  local_2f8 = (local_2e4 * local_2d4 + local_2d8 * local_2f0 + local_2d0 * local_2e8) -
              local_2dc * local_2ec;
  local_2f4 = (local_2e4 * local_2d8 + local_2dc * local_2e8 + local_2d0 * local_2ec) -
              local_2d4 * local_2f0;
  local_2c4 = (local_2e4 * local_2dc + local_2d0 * local_2f0 + local_2d4 * local_2ec) -
              local_2d8 * local_2e8;
  FUN_0061a080(&local_2c4,&local_2f4,&local_2f8,&local_2e0);
  FUN_0061abb0(&local_2c0);
  local_2dc = local_2c0;
  local_2d8 = local_2bc;
  local_2d0 = local_2b4;
  local_2d4 = local_2b8;
  FUN_0061abb0(&local_2f0);
  local_2c4 = ((local_2d0 * local_2e4 - local_2dc * local_2f0) - local_2d8 * local_2ec) -
              local_2d4 * local_2e8;
  local_2e0 = (local_2d4 * local_2e4 + local_2d8 * local_2f0 + local_2d0 * local_2e8) -
              local_2dc * local_2ec;
  local_2f8 = (local_2d8 * local_2e4 + local_2d0 * local_2ec + local_2dc * local_2e8) -
              local_2d4 * local_2f0;
  local_2f4 = (local_2d0 * local_2f0 + local_2d4 * local_2ec + local_2dc * local_2e4) -
              local_2d8 * local_2e8;
  FUN_0061a080(&local_2f4,&local_2f8,&local_2e0,&local_2c4);
  local_2c4 = -local_248;
  local_2e0 = -local_24c;
  local_2f8 = -local_250;
  FUN_0061a080(&local_2f8,&local_2e0,&local_2c4,local_244);
  local_2f4 = ((local_274 * local_2e4 - local_280 * local_2f0) - local_27c * local_2ec) -
              local_278 * local_2e8;
  local_2cc = (local_278 * local_2e4 + local_2e8 * local_274 + local_27c * local_2f0) -
              local_2ec * local_280;
  local_2c8 = (local_27c * local_2e4 + local_2ec * local_274 + local_2e8 * local_280) -
              local_278 * local_2f0;
  local_2fc = (local_278 * local_2ec + local_274 * local_2f0 + local_2e4 * local_280) -
              local_2e8 * local_27c;
  FUN_0061a080(&local_2fc,&local_2c8,&local_2cc,&local_2f4);
  FUN_006466f0(&local_2c0,&local_290,&DAT_00f3f820);
  uVar2 = FUN_0061a120(local_2a0);
  FUN_00646660(uVar2);
  FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
  fVar6 = (float10)FUN_005fcc30(local_230);
  local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a860(&local_2fc);
  FUN_006170e0(&local_260,local_230);
  fVar6 = (float10)FUN_005fcc30(local_230);
  if ((float10)_DAT_00804918 <= fVar6) {
    pfVar11 = &local_2c8;
    pfVar10 = &local_2cc;
    pfVar9 = &local_2c4;
    fVar6 = SQRT(fVar6 + (float10)_DAT_00804108 + fVar6 + (float10)_DAT_00804108);
    local_2f8 = (float)((float10)_DAT_00804108 / fVar6);
    local_2fc = (float)(fVar6 * (float10)_DAT_007d589c);
    local_2c8 = local_2f8 * local_258;
    local_2cc = local_2f8 * local_25c;
    local_2c4 = local_260 * local_2f8;
  }
  else {
    FUN_00619f90(&DAT_00f3f820,&local_270,local_2a0);
    pfVar11 = local_268;
    pfVar10 = &local_26c;
    pfVar9 = &local_270;
    local_2fc = 0.0;
  }
  FUN_0061a080(pfVar9,pfVar10,pfVar11,&local_2fc);
  fVar6 = (float10)FUN_0061a2f0(&local_2b0);
  local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a880(&local_2fc);
  local_2fc = -local_2a8;
  local_2c8 = -local_2ac;
  local_2cc = -local_2b0;
  FUN_0061a080(&local_2cc,&local_2c8,&local_2fc,&local_2a4);
  local_2c4 = ((local_284 * local_2e4 - local_290 * local_2f0) - local_28c * local_2ec) -
              local_288 * local_2e8;
  local_2e0 = (local_288 * local_2e4 + local_2e8 * local_284 + local_28c * local_2f0) -
              local_2ec * local_290;
  local_2f8 = (local_28c * local_2e4 + local_2ec * local_284 + local_2e8 * local_290) -
              local_288 * local_2f0;
  local_2f4 = (local_288 * local_2ec + local_284 * local_2f0 + local_2e4 * local_290) -
              local_2e8 * local_28c;
  FUN_0061a080(&local_2f4,&local_2f8,&local_2e0,&local_2c4);
  fVar6 = (float10)FUN_0061a2f0(local_240);
  local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a880(&local_2fc);
  if ((*(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e0)) &&
     (*(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e4))) {
    local_2f8 = 0.0;
    FUN_00645080(&local_2b0,&local_2f4,&local_2f0,&local_2f8);
    fVar1 = local_2f8 * *(float *)(param_1 + 0x1d0);
    if (fVar1 < local_2f4) {
      *(undefined1 *)(param_1 + 0x232) = 1;
      *(undefined4 *)(param_1 + 0x234) = 0x3f800000;
      if ((local_2f4 < local_2f8) && (*(float *)(param_1 + 0x1d0) < _DAT_00804928)) {
        *(float *)(param_1 + 0x234) = (local_2f4 - fVar1) / (local_2f8 - fVar1);
      }
      *(float *)(param_1 + 0x21c) = local_2f4 - fVar1;
      local_2e0 = -local_2e8;
      if ((float)_DAT_00804920 < ABS(local_2ec)) {
        local_2e8 = ABS((*(float *)(param_1 + 0x1e4) / *(float *)(param_1 + 0x1e0)) *
                        (local_2e0 / local_2ec) * local_2ec);
        if (local_2e0 <= _DAT_007d5344) {
          local_2e8 = -local_2e8;
        }
        local_2e8 = -local_2e8;
        fVar6 = (float10)FUN_005fcc30(&local_2f0);
        local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
        FUN_0061a860(&local_2fc);
      }
      local_2fc = -local_2e8;
      local_2c8 = -local_2ec;
      local_2cc = -local_2f0;
      FUN_005fc500(&local_2cc,&local_2c8,&local_2fc);
      FUN_006466f0(&local_2c0,&local_250,local_2a0);
      uVar2 = FUN_0061a120(&local_270);
      FUN_00646660(uVar2);
      FUN_005fc500(&local_2c0,&local_2bc,&local_2b8);
      pfVar11 = (float *)(param_1 + 0x1f0);
      *pfVar11 = local_2dc;
      *(float *)(param_1 + 500) = local_2d8;
      *(float *)(param_1 + 0x1f8) = local_2d4;
      *(float *)(param_1 + 0x1fc) = local_2d0;
      *(undefined4 *)(param_1 + 0x23c) = 0;
      *(undefined4 *)(param_1 + 0x240) = 0;
      *(undefined4 *)(param_1 + 0x244) = 0;
      *(undefined4 *)(param_1 + 0x248) = 0;
      FUN_0063ab90(&local_270,pfVar11,param_4);
      FUN_0063ab90(local_2a0,pfVar11,param_5);
      fVar6 = (float10)FUN_005fcc30(local_2a0);
      local_2fc = (float)fVar6;
      fVar6 = (float10)FUN_005fcc30(&local_270);
      *(float *)(param_1 + 0x210) = (float)((float10)_DAT_00804108 / (fVar6 + (float10)local_2fc));
    }
    goto LAB_00644ec2;
  }
  FUN_005fc500(param_1 + 0x150,param_1 + 0x160,param_1 + 0x170);
  fVar6 = (float10)FUN_005fcc30(local_2a0);
  local_2fc = (float)fVar6;
  fVar6 = (float10)FUN_005fcc30(local_2a0);
  local_2c8 = (float)fVar6;
  fVar6 = (float10)FUN_005fcc30(local_2a0);
  local_2cc = (float)fVar6;
  FUN_005fc500(&local_2cc,&local_2c8,&local_2fc);
  FUN_005fc500(param_1 + 0x154,param_1 + 0x164,param_1 + 0x174);
  FUN_005fc730(&local_270,param_2,local_2a0);
  uVar2 = FUN_0061a320(local_2a0,2);
  FUN_005fc730(&local_260,param_2,uVar2);
  uVar2 = FUN_0061a320(local_2a0,0);
  FUN_005fc730(&local_2c0,param_3,uVar2);
  fVar6 = (float10)FUN_005fcc30(&local_2dc);
  local_2f8 = (float)fVar6;
  fVar6 = (float10)FUN_005fcc30(&local_270);
  local_2f4 = (float)fVar6;
  fVar6 = (float10)FUN_005fcc30(&local_260);
  if ((*(float *)(param_1 + 0x1e0) < *(float *)(param_1 + 0x1ec)) &&
     (*(float *)(param_1 + 0x1e4) < *(float *)(param_1 + 0x1ec))) {
    if ((_DAT_00804520 <= ABS(local_2f4)) || ((float10)_DAT_00804520 <= ABS(fVar6))) {
      *(undefined1 *)(param_1 + 0x232) = 1;
      uVar2 = FUN_006170e0(local_2a0,&local_2dc);
      puVar5 = (undefined4 *)FUN_005fc5c0(local_220,uVar2);
      *(undefined4 *)(param_1 + 0x1f0) = *puVar5;
      *(undefined4 *)(param_1 + 500) = puVar5[1];
      *(undefined4 *)(param_1 + 0x1f8) = puVar5[2];
      *(undefined4 *)(param_1 + 0x1fc) = puVar5[3];
    }
    goto LAB_00644ec2;
  }
  if (*(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e0)) {
    if ((float10)_DAT_00804520 <= ABS(fVar6)) {
      fVar6 = (float10)_DAT_007d5344;
      fVar8 = (float10)fpatan((float10)local_2f4,(float10)local_2f8);
      *(undefined1 *)(param_1 + 0x232) = 1;
      if (fVar8 <= (float10)*(float *)(param_1 + 0x1e0)) {
        if (-(float10)*(float *)(param_1 + 0x1e0) <= fVar8) goto LAB_00644db8;
        fVar8 = (float10)fcos((float10)*(float *)(param_1 + 0x1e0));
        fVar7 = (float10)fsin((float10)*(float *)(param_1 + 0x1e0));
        fVar7 = -fVar7;
      }
      else {
        fVar8 = (float10)fcos((float10)*(float *)(param_1 + 0x1e0));
        fVar7 = (float10)fsin((float10)*(float *)(param_1 + 0x1e0));
      }
      local_2f8 = (float)fVar8;
      local_2f4 = (float)fVar7;
    }
  }
  else if ((_DAT_00804520 <= ABS(local_2f4)) &&
          (*(undefined1 *)(param_1 + 0x232) = 1,
          *(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e4))) {
    fVar8 = (float10)fpatan(fVar6,(float10)local_2f8);
    local_2f4 = 0.0;
    if (fVar8 <= (float10)*(float *)(param_1 + 0x1e4)) {
      if (fVar8 < -(float10)*(float *)(param_1 + 0x1e4)) {
        fVar6 = (float10)fcos((float10)*(float *)(param_1 + 0x1e4));
        local_2f8 = (float)fVar6;
        fVar6 = (float10)fsin((float10)*(float *)(param_1 + 0x1e4));
        fVar6 = -fVar6;
      }
    }
    else {
      fVar6 = (float10)fcos((float10)*(float *)(param_1 + 0x1e4));
      local_2f8 = (float)fVar6;
      fVar6 = (float10)fsin((float10)*(float *)(param_1 + 0x1e4));
    }
  }
LAB_00644db8:
  local_2f0 = (float)((float10)local_2dc * (float10)local_2f8 +
                     (float10)local_270 * (float10)local_2f4 + (float10)local_260 * fVar6);
  local_2ec = (float)((float10)local_2d8 * (float10)local_2f8 +
                     (float10)local_26c * (float10)local_2f4 + (float10)local_25c * fVar6);
  local_2e8 = (float)((float10)local_2d4 * (float10)local_2f8 +
                     (float10)local_268[0] * (float10)local_2f4 + (float10)local_258 * fVar6);
  fVar6 = (float10)FUN_005fcc30(&local_2f0);
  local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a860(&local_2fc);
  puVar5 = (undefined4 *)(param_1 + 0x1f0);
  uVar2 = FUN_006170e0(local_220,&local_2f0);
  puVar4 = (undefined4 *)FUN_005fc5c0(local_2a0,uVar2);
  *puVar5 = *puVar4;
  *(undefined4 *)(param_1 + 500) = puVar4[1];
  *(undefined4 *)(param_1 + 0x1f8) = puVar4[2];
  *(undefined4 *)(param_1 + 0x1fc) = puVar4[3];
  fVar6 = (float10)FUN_005fcc30(puVar5);
  *(float *)(param_1 + 0x21c) = (float)SQRT(fVar6);
  fVar6 = (float10)FUN_005fcc30(puVar5);
  local_2fc = (float)((float10)_DAT_00804108 / SQRT(fVar6));
  FUN_0061a860(&local_2fc);
LAB_00644ec2:
  if (*(float *)(param_1 + 0x1e8) < _DAT_007d5344) {
    *(undefined4 *)(param_1 + 0x224) = 0;
  }
  else {
    pfVar11 = (float *)(param_1 + 0x224);
    FUN_00645360(local_240,pfVar11,local_2a0);
    fVar1 = *(float *)(param_1 + 0x1d0) * *(float *)(param_1 + 0x1e8);
    if (fVar1 < *pfVar11) {
      *(undefined1 *)(param_1 + 0x231) = 1;
      *(undefined4 *)(param_1 + 0x238) = 0x3f800000;
      if ((*pfVar11 < *(float *)(param_1 + 0x1e8)) && (*(float *)(param_1 + 0x1d0) < _DAT_00804928))
      {
        *(float *)(param_1 + 0x238) = (*pfVar11 - fVar1) / (*(float *)(param_1 + 0x1e8) - fVar1);
      }
      puVar5 = (undefined4 *)(param_1 + 0x200);
      *(float *)(param_1 + 0x220) = *pfVar11 - fVar1;
      uVar2 = FUN_005fc5c0(local_220,local_2a0);
      puVar4 = (undefined4 *)FUN_00646250(&local_270,&local_250,uVar2);
      *puVar5 = *puVar4;
      *(undefined4 *)(param_1 + 0x204) = puVar4[1];
      *(undefined4 *)(param_1 + 0x208) = puVar4[2];
      *(undefined4 *)(param_1 + 0x20c) = puVar4[3];
      FUN_0063ab90(&local_260,puVar5,param_4);
      FUN_0063ab90(&local_270,puVar5,param_5);
      fVar6 = (float10)FUN_005fcc30(&local_270);
      local_2fc = (float)fVar6;
      fVar6 = (float10)FUN_005fcc30(&local_260);
      *(float *)(param_1 + 0x214) = (float)((float10)_DAT_00804108 / (fVar6 + (float10)local_2fc));
    }
    if (*(char *)(param_1 + 0x232) != '\0') {
      uVar2 = FUN_005fc5c0(local_220,local_2a0);
      puVar5 = (undefined4 *)FUN_00646250(&local_270,&local_280,uVar2);
      *(undefined4 *)(param_1 + 0x23c) = *puVar5;
      *(undefined4 *)(param_1 + 0x240) = puVar5[1];
      *(undefined4 *)(param_1 + 0x244) = puVar5[2];
      *(undefined4 *)(param_1 + 0x248) = puVar5[3];
      return;
    }
  }
  return;
}


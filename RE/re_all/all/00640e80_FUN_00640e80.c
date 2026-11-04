
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00640e80(int param_1,float *param_2,int param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 uVar8;
  float *pfVar9;
  int iVar10;
  float10 fVar11;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0 [2];
  float local_a8;
  float local_a4;
  undefined1 local_a0 [16];
  float local_90 [4];
  float local_80 [5];
  float local_6c;
  float local_68;
  float local_5c;
  float local_58;
  float local_4c;
  float local_48;
  undefined1 local_30 [48];
  
  FUN_00643fa0(param_3,param_4,param_5,param_6);
  *(undefined4 *)param_2[2] = 0x3f800000;
  *(undefined4 *)((int)param_2[2] + 4 + (int)param_2[6] * 4) = 0x3f800000;
  *(undefined4 *)((int)param_2[2] + 8 + (int)param_2[6] * 8) = 0x3f800000;
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x180);
  local_a8 = (float)fVar11;
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x180);
  local_a4 = (float)fVar11;
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x180);
  local_c0 = (float)fVar11;
  FUN_005fc500(&local_c0,&local_a4,&local_a8);
  local_bc = param_2[3];
  local_c0 = -local_80[2];
  local_a4 = -local_80[1];
  local_c4 = (float)((int)local_bc + (int)param_2[6] * 4);
  local_c8 = (float)((int)local_bc + (int)param_2[6] * 8);
  local_a8 = -local_80[0];
  FUN_005fc500(&local_a8,&local_a4,&local_c0);
  local_c0 = -local_b0[0];
  local_a4 = 0.0;
  FUN_005fc530(&local_a4,&local_c0,&local_b4);
  local_bc = -local_b8;
  local_c0 = 0.0;
  FUN_005fc530(local_b0,&local_c0,&local_bc);
  local_bc = -local_b4;
  local_c4 = 0.0;
  FUN_005fc530(&local_bc,&local_b8,&local_c4);
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x1c0);
  local_c8 = (float)fVar11;
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x1c0);
  local_c4 = (float)fVar11;
  fVar11 = (float10)FUN_005fcc30(param_1 + 0x1c0);
  local_bc = (float)fVar11;
  FUN_005fc500(&local_bc,&local_c4,&local_c8);
  local_bc = (float)((int)param_2[5] + (int)param_2[6] * 4);
  local_c0 = (float)((int)param_2[5] + (int)param_2[6] * 8);
  local_c8 = -local_90[2];
  local_c4 = 0.0;
  FUN_005fc530(&local_c4,&local_c8,local_90 + 1);
  local_c8 = -local_90[0];
  local_c4 = 0.0;
  FUN_005fc530(local_90 + 2,&local_c4,&local_c8);
  local_c8 = 0.0;
  local_c4 = -local_90[1];
  FUN_005fc530(&local_c4,local_90,&local_c8);
  fVar2 = param_2[1];
  fVar3 = *param_2;
  iVar7 = 0;
  pfVar9 = (float *)(param_3 + 0x30);
  do {
    pfVar1 = (float *)((param_4 - param_3) + (int)pfVar9);
    fVar4 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    *(float *)((int)param_2[7] + iVar7 * (int)param_2[6] * 4) =
         (((local_90[iVar7] + *pfVar1) - local_80[iVar7]) - fVar4) * fVar2 * fVar3;
    *(undefined4 *)((int)param_2[9] + iVar7 * (int)param_2[6] * 4) = 0xff7fffff;
    iVar10 = iVar7 * (int)param_2[6];
    iVar7 = iVar7 + 1;
    *(undefined4 *)((int)param_2[10] + iVar10 * 4) = 0x7f7fffff;
  } while (iVar7 < 3);
  fVar2 = param_2[6];
  iVar7 = (int)fVar2 * 3;
  if (*(char *)(param_1 + 0x232) != '\0') {
    local_c8 = param_2[3];
    local_c4 = param_2[5];
    if ((*(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e0)) ||
       (*(float *)(param_1 + 0x1ec) <= *(float *)(param_1 + 0x1e4))) {
      fVar3 = *(float *)(param_1 + 0x1f0) * *(float *)(param_1 + 0x1d8) *
              *(float *)(param_1 + 0x1d8);
      fVar4 = *(float *)(param_1 + 500) * *(float *)(param_1 + 0x1d8) * *(float *)(param_1 + 0x1d8);
      fVar5 = *(float *)(param_1 + 0x1f8) * *(float *)(param_1 + 0x1d8) *
              *(float *)(param_1 + 0x1d8);
      *(float *)((int)local_c8 + (int)fVar2 * 0xc) = fVar3;
      *(float *)((int)local_c8 + 4 + (int)fVar2 * 0xc) = fVar4;
      *(float *)((int)local_c8 + 8 + (int)fVar2 * 0xc) = fVar5;
      *(float *)((int)local_c4 + (int)fVar2 * 0xc) = -fVar3;
      *(float *)((int)local_c4 + 4 + (int)fVar2 * 0xc) = -fVar4;
      *(float *)((int)local_c4 + 8 + (int)fVar2 * 0xc) = -fVar5;
      *(float *)((int)param_2[7] + (int)fVar2 * 0xc) =
           *(float *)(param_1 + 0x1d4) * *param_2 * *(float *)(param_1 + 0x21c);
      *(undefined4 *)((int)param_2[8] + (int)fVar2 * 0xc) = 0;
      *(undefined4 *)((int)param_2[9] + (int)fVar2 * 0xc) = 0;
      *(undefined4 *)((int)param_2[10] + (int)fVar2 * 0xc) = 0x7f7fffff;
      iVar7 = iVar7 + (int)param_2[6];
    }
    else {
      FUN_005fc8d0(local_a0,param_1 + 0x180);
      uVar8 = FUN_005fc790(local_30,param_3,param_1 + 0x150);
      FUN_005fc5f0(uVar8);
      fVar3 = param_2[6];
      *(float *)((int)local_c8 + (int)fVar2 * 0xc) = local_6c;
      *(float *)((int)local_c8 + 4 + (int)fVar2 * 0xc) = local_5c;
      *(float *)((int)local_c8 + 8 + (int)fVar2 * 0xc) = local_4c;
      iVar7 = iVar7 + (int)fVar3;
      *(float *)((int)local_c8 + iVar7 * 4) = local_68;
      *(float *)((int)local_c8 + 4 + iVar7 * 4) = local_58;
      *(float *)((int)local_c8 + 8 + iVar7 * 4) = local_48;
      *(float *)((int)local_c4 + (int)fVar2 * 0xc) = -local_6c;
      *(float *)((int)local_c4 + 4 + (int)fVar2 * 0xc) = -local_5c;
      *(float *)((int)local_c4 + 8 + (int)fVar2 * 0xc) = -local_4c;
      *(float *)((int)local_c4 + iVar7 * 4) = -local_68;
      *(float *)((int)local_c4 + 4 + iVar7 * 4) = -local_58;
      *(float *)((int)local_c4 + 8 + iVar7 * 4) = -local_48;
      fVar3 = *(float *)(param_1 + 0x1d8) * *param_2;
      *(float *)((int)param_2[7] + (int)fVar2 * 0xc) =
           (local_6c * *(float *)(param_1 + 0x1f0) +
           local_5c * *(float *)(param_1 + 500) + local_4c * *(float *)(param_1 + 0x1f8)) * fVar3;
      *(float *)((int)param_2[7] + iVar7 * 4) =
           (local_68 * *(float *)(param_1 + 0x1f0) +
           local_58 * *(float *)(param_1 + 500) + local_48 * *(float *)(param_1 + 0x1f8)) * fVar3;
      *(undefined4 *)((int)param_2[9] + (int)fVar2 * 0xc) = 0xff7fffff;
      *(undefined4 *)((int)param_2[10] + (int)fVar2 * 0xc) = 0x7f7fffff;
      *(undefined4 *)((int)param_2[9] + iVar7 * 4) = 0xff7fffff;
      *(undefined4 *)((int)param_2[10] + iVar7 * 4) = 0x7f7fffff;
      iVar7 = iVar7 + (int)param_2[6];
    }
  }
  if (*(char *)(param_1 + 0x231) != '\0') {
    fVar2 = param_2[3];
    fVar3 = param_2[5];
    fVar4 = *(float *)(param_1 + 0x1d8) * *(float *)(param_1 + 0x200) * *(float *)(param_1 + 0x1d8);
    fVar5 = *(float *)(param_1 + 0x204) * *(float *)(param_1 + 0x1d8) * *(float *)(param_1 + 0x1d8);
    fVar6 = *(float *)(param_1 + 0x208) * *(float *)(param_1 + 0x1d8) * *(float *)(param_1 + 0x1d8);
    *(float *)((int)fVar2 + iVar7 * 4) = fVar4;
    *(float *)((int)fVar2 + 4 + iVar7 * 4) = fVar5;
    *(float *)((int)fVar2 + 8 + iVar7 * 4) = fVar6;
    *(float *)((int)fVar3 + iVar7 * 4) = -fVar4;
    *(float *)((int)fVar3 + 4 + iVar7 * 4) = -fVar5;
    *(float *)((int)fVar3 + 8 + iVar7 * 4) = -fVar6;
    *(float *)((int)param_2[7] + iVar7 * 4) =
         *(float *)(param_1 + 0x1d4) * *param_2 * *(float *)(param_1 + 0x220);
    *(undefined4 *)((int)param_2[8] + iVar7 * 4) = 0;
    if (_DAT_007d5344 < *(float *)(param_1 + 0x1e8)) {
      if (*(float *)(param_1 + 0x220) <= _DAT_007d5344) {
        *(undefined4 *)((int)param_2[9] + iVar7 * 4) = 0xff7fffff;
        *(undefined4 *)((int)param_2[10] + iVar7 * 4) = 0;
        return;
      }
      *(undefined4 *)((int)param_2[9] + iVar7 * 4) = 0;
      *(undefined4 *)((int)param_2[10] + iVar7 * 4) = 0x7f7fffff;
      return;
    }
    *(undefined4 *)((int)param_2[9] + iVar7 * 4) = 0xff7fffff;
    *(undefined4 *)((int)param_2[10] + iVar7 * 4) = 0x7f7fffff;
  }
  return;
}


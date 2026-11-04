
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00635d20(int *param_1,float *param_2,float *param_3,float *param_4,float param_5,float param_6,
            float param_7,float param_8,float param_9,undefined4 param_10,float param_11)

{
  float *pfVar1;
  bool bVar2;
  int iVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar4;
  float10 fVar5;
  float *pfVar6;
  int local_a30;
  bool local_a2b;
  bool local_a29;
  int local_a28;
  float local_a24;
  float local_a20;
  int local_a1c;
  int local_a18;
  float local_a14;
  float *local_a10;
  int local_a0c;
  float *local_a08;
  float local_a04;
  float local_a00;
  float fStack_9fc;
  float local_9f8;
  float local_9f4;
  float fStack_9f0;
  float local_9ec;
  float local_9e8;
  float local_9e4;
  float local_9e0;
  float local_9dc;
  float local_9d8;
  float local_9d4;
  float local_9d0;
  float local_9cc;
  float local_9c8;
  float local_9c4;
  float local_9c0;
  float local_9bc;
  float local_9b8;
  float local_9b0;
  float local_9ac;
  float local_9a8;
  undefined4 local_9a4;
  float local_9a0;
  float local_99c;
  float local_998;
  undefined4 local_994;
  float local_98c;
  float local_988;
  float local_980;
  float local_97c;
  float local_978;
  float local_96c;
  float local_968;
  float local_95c;
  float local_958;
  float local_950;
  float local_94c;
  float local_948;
  float local_940 [296];
  float local_4a0 [296];
  
  local_a08 = local_940;
  local_a10 = local_4a0;
  local_9a4 = 0;
  local_a14 = param_5 * param_3[1];
  local_994 = 0;
  local_a20 = param_5 * param_3[2];
  local_9b0 = param_5 * *param_3 + *param_2;
  local_9ac = local_a14 + param_2[1];
  local_9a8 = local_a20 + param_2[2];
  local_9a0 = *param_2 - param_5 * *param_3;
  local_99c = param_2[1] - local_a14;
  local_998 = param_2[2] - local_a20;
  param_11 = param_11 * _DAT_00804860;
  local_9c0 = param_4[2] * param_3[1] - param_4[1] * param_3[2];
  local_9bc = param_3[2] * *param_4 - param_4[2] * *param_3;
  local_9b8 = param_4[1] * *param_3 - *param_4 * param_3[1];
  local_a29 = param_6 <= _DAT_00804868;
  if (local_a29) {
    param_6 = param_11 - _DAT_00804864;
  }
  bVar2 = _DAT_00804864 <= param_7;
  if (bVar2) {
    param_7 = _DAT_00804864 - param_11;
  }
  local_a2b = param_7 < param_6;
  if (local_a2b) {
    param_6 = param_11 - _DAT_00804864;
  }
  local_a29 = local_a2b || local_a29;
  local_a2b = local_a2b || bVar2;
  local_9f8 = local_a14;
  local_9f4 = local_a20;
  local_a1c = __ftol();
  local_a1c = local_a1c + 1;
  if (local_a1c < 2) {
    local_a1c = 2;
  }
  local_a0c = local_a1c + -1;
  local_9cc = (float)(extraout_ST0 / (float10)local_a0c);
  if (param_8 <= param_9) {
    bVar2 = true;
    if (param_9 - param_8 < _DAT_00802ec0) {
      bVar2 = false;
    }
  }
  else {
    param_8 = param_11 - _DAT_00802ebc;
    bVar2 = true;
  }
  local_a18 = __ftol();
  local_a18 = local_a18 + 1;
  if (local_a18 < 2) {
    local_a18 = 2;
  }
  local_a20 = (float)(local_a18 + -1);
  local_a28 = 0;
  local_9ec = (float)(extraout_ST0_00 / (float10)(int)local_a20);
  iVar3 = local_a18;
  if (0 < local_a1c) {
    do {
      local_a30 = 0;
      fVar4 = (float10)local_a28 * (float10)local_9cc + (float10)param_6;
      fVar5 = (float10)fsin(fVar4);
      local_a04 = (float)(fVar5 * (float10)param_5);
      fVar4 = (float10)fcos(fVar4);
      local_a14 = (float)(fVar4 * (float10)param_5);
      if (0 < iVar3) {
        local_9d0 = 0.0;
        do {
          fVar4 = (float10)local_a30 * (float10)local_9ec + (float10)param_8;
          fVar5 = (float10)fsin(fVar4);
          local_a24 = (float)(fVar5 * (float10)local_a14);
          fVar4 = (float10)fcos(fVar4);
          local_a00 = (float)(fVar4 * (float10)local_a14);
          local_9c8 = local_a04 * param_3[2];
          local_9e0 = local_a04 * param_3[1];
          local_9c4 = local_a04 * *param_3;
          FUN_005fc500(&local_9c4,&local_9e0,&local_9c8);
          local_9e8 = local_9b8 * local_a24;
          local_9e4 = local_9bc * local_a24;
          local_a24 = local_9c0 * local_a24;
          FUN_005fc500(&local_a24,&local_9e4,&local_9e8);
          local_95c = local_a00 * param_4[1];
          local_958 = local_a00 * param_4[2];
          local_98c = local_95c + param_2[1];
          local_988 = local_958 + param_2[2];
          local_96c = local_94c + local_98c;
          local_968 = local_948 + local_988;
          local_9dc = local_a00 * *param_4 + *param_2 + local_950 + local_980;
          local_9d8 = local_97c + local_96c;
          local_9d4 = local_978 + local_968;
          pfVar1 = local_a10 + local_a30 * 4;
          *pfVar1 = local_9dc;
          pfVar1[1] = local_9d8;
          pfVar1[2] = local_9d4;
          pfVar1[3] = local_9d0;
          if (local_a28 == 0) {
            if (local_a2b) {
              iVar3 = *param_1;
              pfVar6 = &local_9a0;
              goto LAB_006361ca;
            }
          }
          else {
            iVar3 = *param_1;
            pfVar6 = local_a08 + local_a30 * 4;
LAB_006361ca:
            (**(code **)(iVar3 + 4))(pfVar6,pfVar1,param_10);
          }
          if (local_a30 == 0) {
            fStack_9fc = *local_a10;
            local_9f8 = local_a10[1];
            local_9f4 = local_a10[2];
            fStack_9f0 = local_a10[3];
          }
          else {
            (**(code **)(*param_1 + 4))(pfVar1 + -4,pfVar1,param_10);
          }
          if ((local_a28 == local_a0c) && (local_a29)) {
            (**(code **)(*param_1 + 4))(&local_9b0,pfVar1,param_10);
          }
          if (bVar2) {
            if ((float)local_a30 == local_a20) {
              iVar3 = *param_1;
              pfVar6 = &fStack_9fc;
LAB_00636286:
              (**(code **)(iVar3 + 4))(pfVar6,pfVar1,param_10);
            }
          }
          else if (((local_a28 == 0) || (local_a28 == local_a0c)) &&
                  ((local_a30 == 0 || ((float)local_a30 == local_a20)))) {
            iVar3 = *param_1;
            pfVar6 = param_2;
            goto LAB_00636286;
          }
          local_a30 = local_a30 + 1;
        } while (local_a30 < local_a18);
        iVar3 = local_a18;
      }
      pfVar1 = local_a10;
      local_a10 = local_a08;
      local_a08 = pfVar1;
      local_a28 = local_a28 + 1;
    } while (local_a28 < local_a1c);
  }
  return;
}


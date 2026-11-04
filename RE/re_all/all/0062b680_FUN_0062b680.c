
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062b680(float *param_1,float *param_2,float *param_3)

{
  bool bVar1;
  ushort uVar2;
  float10 fVar3;
  undefined2 extraout_var;
  undefined4 uVar4;
  float10 fVar5;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_80;
  float local_7c;
  float local_78;
  undefined1 local_60 [48];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  local_90 = param_1[4] - *param_1;
  local_8c = param_1[5] - param_1[1];
  local_88 = param_1[6] - param_1[2];
  local_9c = param_1[10] - param_1[6];
  local_94 = param_1[9] - param_1[5];
  local_98 = param_1[8] - param_1[4];
  FUN_005fc500(&local_98,&local_94,&local_9c);
  local_98 = param_1[2] - param_1[10];
  local_94 = param_1[1] - param_1[9];
  local_9c = *param_1 - param_1[8];
  FUN_005fc500(&local_9c,&local_94,&local_98);
  local_98 = param_3[2] - param_1[2];
  local_94 = param_3[1] - param_1[1];
  local_9c = *param_3 - *param_1;
  FUN_005fc500(&local_9c,&local_94,&local_98);
  local_98 = param_3[2] - param_1[6];
  local_94 = param_3[1] - param_1[5];
  local_9c = *param_3 - param_1[4];
  FUN_005fc500(&local_9c,&local_94,&local_98);
  local_98 = param_3[2] - param_1[10];
  local_94 = param_3[1] - param_1[9];
  local_9c = *param_3 - param_1[8];
  FUN_005fc500(&local_9c,&local_94,&local_98);
  local_98 = local_90 * param_2[1] - local_8c * *param_2;
  local_94 = local_88 * *param_2 - local_90 * param_2[2];
  local_9c = local_8c * param_2[2] - local_88 * param_2[1];
  FUN_005fc500(&local_9c,&local_94,&local_98);
  local_98 = local_80 * param_2[1] - local_7c * *param_2;
  local_94 = local_78 * *param_2 - local_80 * param_2[2];
  local_9c = local_7c * param_2[2] - local_78 * param_2[1];
  FUN_005fc500(&local_9c,&local_94,&local_98);
  FUN_006170e0(local_10,param_2);
  fVar5 = (float10)FUN_005fcc30(local_20);
  local_98 = (float)fVar5;
  fVar5 = (float10)FUN_005fcc30(local_60);
  local_9c = (float)fVar5;
  fVar5 = (float10)FUN_005fcc30(local_30);
  bVar1 = local_9c < _DAT_007d5344;
  uVar2 = (ushort)(local_9c == _DAT_007d5344);
  uVar4 = CONCAT22(extraout_var,
                   (ushort)bVar1 << 8 | (ushort)(NAN(local_9c) || NAN(_DAT_007d5344)) << 10 |
                   uVar2 << 0xe);
  if (local_98 <= _DAT_007d5344) {
    if (bVar1 || uVar2 != 0) {
      fVar3 = (float10)_DAT_007d5344;
      uVar4 = CONCAT22(extraout_var,
                       (ushort)(fVar5 < fVar3) << 8 | (ushort)(NAN(fVar5) || NAN(fVar3)) << 10 |
                       (ushort)(fVar5 == fVar3) << 0xe);
      if (fVar5 < fVar3 || (fVar5 == fVar3) != 0) goto LAB_0062b905;
    }
  }
  else if (!bVar1 && uVar2 == 0) {
    fVar3 = (float10)_DAT_007d5344;
    uVar4 = CONCAT22(extraout_var,
                     (ushort)(fVar5 < fVar3) << 8 | (ushort)(NAN(fVar5) || NAN(fVar3)) << 10 |
                     (ushort)(fVar5 == fVar3) << 0xe);
    if (fVar5 < fVar3 || (fVar5 == fVar3) != 0) {
      return uVar4;
    }
LAB_0062b905:
    return CONCAT31((int3)((uint)uVar4 >> 8),1);
  }
  return uVar4;
}



void __thiscall FUN_007927c0(int param_1,undefined4 param_2,float *param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort uVar7;
  ushort *puVar8;
  float local_30;
  ushort local_2c;
  undefined4 local_28;
  ushort local_24;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  local_30 = param_3[1] - *(float *)(param_1 + 8);
  local_28 = *param_3 - *(float *)(param_1 + 4);
  param_3 = (float *)(param_3[2] - *(float *)(param_1 + 0xc));
  FUN_005fc500(&local_28,&local_30,&param_3);
  FUN_005fc560(local_20,local_10,param_1 + 0x24);
  uVar1 = __ftol();
  uVar2 = __ftol();
  local_2c = __ftol();
  local_2c = local_2c & 0xfffe;
  uVar4 = FUN_005fc590(local_10,param_4,(float *)(param_1 + 4),param_1 + 0x24);
  FUN_005fc560(local_20,uVar4);
  uVar3 = __ftol();
  local_28 = (float)(CONCAT22(local_28._2_2_,uVar3) | 1);
  uVar3 = __ftol();
  local_28 = (float)(CONCAT22(uVar3,(ushort)local_28) | 0x10000);
  local_24 = __ftol();
  local_24 = local_24 | 1;
  param_3 = (float *)0x0;
  if (0 < *(int *)(param_1 + 0x98)) {
    param_4 = 0;
    uVar7 = local_24;
    do {
      puVar8 = (ushort *)(param_4 + *(int *)(param_1 + 0xa0));
      uVar5 = (uint)(((((local_2c <= puVar8[5] && (uVar2 & 0xfffe) <= puVar8[4]) &&
                       puVar8[1] <= local_28._2_2_) && (uVar1 & 0xfffe) <= puVar8[3]) &&
                     puVar8[2] <= uVar7) && *puVar8 <= (ushort)local_28);
      if (((int)(-uVar5 | uVar5) >> 0x1f & 1U) != 0) {
        FUN_007929c0(param_2,*(int *)(puVar8 + 6),*(int *)(puVar8 + 8) + *(int *)(puVar8 + 6),
                     param_3);
        puVar6 = (ushort *)(*(int *)(puVar8 + 6) * 0x10 + *(int *)(param_1 + 0x88));
        *puVar8 = *puVar6;
        puVar8[1] = puVar6[1];
        puVar8[2] = puVar6[2];
        puVar8[3] = puVar6[3];
        puVar8[4] = puVar6[4];
        puVar8[5] = puVar6[5];
        uVar7 = local_24;
      }
      param_3 = (float *)((int)param_3 + 1);
      param_4 = param_4 + 0x20;
    } while ((int)param_3 < *(int *)(param_1 + 0x98));
  }
  return;
}


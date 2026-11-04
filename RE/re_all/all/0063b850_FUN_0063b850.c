
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063b850(int param_1,float param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  float10 fVar3;
  float fStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  float local_90;
  float local_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  float fStack_78;
  float local_74;
  undefined1 local_70 [16];
  undefined1 auStack_60 [48];
  undefined1 auStack_30 [48];
  
  if (param_2 != _DAT_007d5344) {
    if (*(int **)(param_1 + 0x1e8) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x1e8) + 4))(param_1 + 4);
    }
    local_74 = *(float *)(param_1 + 0x3c) - *(float *)(param_1 + 0x7c);
    local_8c = *(float *)(param_1 + 0x38) - *(float *)(param_1 + 0x78);
    local_90 = *(float *)(param_1 + 0x34) - *(float *)(param_1 + 0x74);
    FUN_005fc500(&local_90,&local_8c,&local_74);
    fStack_a8 = _DAT_00804108 / param_2;
    fStack_94 = fStack_a8;
    FUN_0060fe40(&uStack_a4,local_70,&fStack_a8);
    *(undefined4 *)(param_1 + 0x130) = uStack_a4;
    *(undefined4 *)(param_1 + 0x134) = uStack_a0;
    *(undefined4 *)(param_1 + 0x138) = uStack_9c;
    *(undefined4 *)(param_1 + 0x13c) = uStack_98;
    uVar1 = FUN_0063cd70(auStack_30);
    FUN_005fc790(auStack_60,(undefined4 *)(param_1 + 4),uVar1);
    FUN_0061abb0(&uStack_a4);
    fVar3 = (float10)FUN_0061a2f0(&uStack_a4);
    fStack_a8 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
    FUN_0061a880(&fStack_a8);
    fVar3 = (float10)FUN_006c5580();
    fStack_78 = (float)(fVar3 + fVar3);
    puVar2 = (undefined4 *)FUN_005fc500(&uStack_a4,&uStack_a0,&uStack_9c);
    uStack_88 = *puVar2;
    uStack_84 = puVar2[1];
    uStack_80 = puVar2[2];
    uStack_7c = 0;
    fVar3 = (float10)FUN_005fcc30(&uStack_88);
    if ((float10)_DAT_0080410c <= fVar3) {
      fStack_a8 = (float)((float10)_DAT_00804108 / SQRT(fVar3));
      FUN_0061a860(&fStack_a8);
    }
    else {
      fStack_a8 = 0.0;
      local_90 = 0.0;
      local_8c = 1.0;
      puVar2 = (undefined4 *)FUN_005fc500(&local_8c,&local_90,&fStack_a8);
      uStack_88 = *puVar2;
      uStack_84 = puVar2[1];
      uStack_80 = puVar2[2];
      uStack_7c = puVar2[3];
    }
    uVar1 = FUN_0060fe40(local_70,&uStack_88,&fStack_78);
    FUN_0060fe40(&uStack_a4,uVar1,&fStack_94);
    *(undefined4 *)(param_1 + 0x140) = uStack_a4;
    *(undefined4 *)(param_1 + 0x144) = uStack_a0;
    *(undefined4 *)(param_1 + 0x148) = uStack_9c;
    *(undefined4 *)(param_1 + 0x14c) = uStack_98;
    *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x130);
    *(undefined4 *)(param_1 + 0x94) = uStack_a4;
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 0x134);
    *(undefined4 *)(param_1 + 0x98) = uStack_a0;
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x138);
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x13c);
    *(undefined4 *)(param_1 + 0x9c) = uStack_9c;
    *(undefined4 *)(param_1 + 0xa0) = uStack_98;
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x40);
  }
  return;
}


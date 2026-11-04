
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0062f5d0(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  undefined4 uVar6;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 200)) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xd0) + iVar4 * 4);
      if (iVar1 != 0) {
        if ((*(int *)(iVar1 + 0xd4) != 2) && (*(int *)(iVar1 + 0xd4) != 4)) {
          fVar2 = *(float *)(iVar1 + 0x1e0);
          fVar5 = (float10)FUN_005fcc30(iVar1 + 0x130);
          if (((float10)fVar2 * (float10)fVar2 <= fVar5) ||
             (*(float *)(iVar1 + 0x1e4) * *(float *)(iVar1 + 0x1e4) <=
              *(float *)(iVar1 + 0x148) * *(float *)(iVar1 + 0x148) +
              *(float *)(iVar1 + 0x144) * *(float *)(iVar1 + 0x144) +
              *(float *)(iVar1 + 0x140) * *(float *)(iVar1 + 0x140))) {
            *(undefined4 *)(iVar1 + 0xd8) = 0;
            FUN_006105d0(0);
          }
          else {
            *(float *)(iVar1 + 0xd8) = param_2 + *(float *)(iVar1 + 0xd8);
          }
        }
        iVar3 = *(int *)(iVar1 + 0xd4);
        if (iVar3 != 4) {
          if (((DAT_00f3f818 != '\0') || (_DAT_00a0625c == _DAT_007d5344)) ||
             ((iVar3 != 2 && ((iVar3 != 3 && (*(float *)(iVar1 + 0xd8) <= _DAT_00a0625c)))))) {
            if (iVar3 != 4) {
              uVar6 = 1;
              goto LAB_0062f7a4;
            }
          }
          else if ((*(byte *)(iVar1 + 200) & 3) == 0) {
            if (iVar3 == 1) {
              FUN_006105d0(3);
            }
            if (*(int *)(iVar1 + 0xd4) == 2) {
              *(undefined4 *)(iVar1 + 0x140) = 0;
              *(undefined4 *)(iVar1 + 0x144) = 0;
              *(undefined4 *)(iVar1 + 0x148) = 0;
              *(undefined4 *)(iVar1 + 0x14c) = 0;
              *(undefined4 *)(iVar1 + 0x130) = 0;
              *(undefined4 *)(iVar1 + 0x134) = 0;
              *(undefined4 *)(iVar1 + 0x138) = 0;
              *(undefined4 *)(iVar1 + 0x13c) = 0;
            }
          }
          else {
            uVar6 = 2;
LAB_0062f7a4:
            FUN_006105d0(uVar6);
          }
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 200));
  }
  return;
}


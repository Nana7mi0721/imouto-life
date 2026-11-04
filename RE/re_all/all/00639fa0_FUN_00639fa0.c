
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_00639fa0(int param_1)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  int *in_stack_00000014;
  int in_stack_00000018;
  int in_stack_0000001c;
  int local_1b0;
  uint local_1ac;
  undefined1 auStack_138 [208];
  undefined1 auStack_68 [104];
  
  iVar11 = *(int *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x44);
  local_1ac = 0;
  if (0 < *(int *)(in_stack_0000001c + 0x14)) {
    do {
      if (((*(byte *)(in_stack_0000001c + 0x3c) & 1) != 0) && ((local_1ac & 7) == 0)) {
        if (0 < iVar11) {
          iVar12 = 0;
          uVar8 = 1;
          do {
            uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x60) + iVar12);
            uVar4 = *(int *)(param_1 + 0x90) * 0x19660d + 0x3c6ef35f;
            *(uint *)(param_1 + 0x90) = uVar4;
            if ((((uVar8 < 0x10001) && (uVar4 = uVar4 ^ uVar4 >> 0x10, uVar8 < 0x101)) &&
                (uVar4 = uVar4 ^ uVar4 >> 8, uVar8 < 0x11)) &&
               ((uVar4 = uVar4 ^ uVar4 >> 4, uVar8 < 5 && (uVar4 = uVar4 ^ uVar4 >> 2, uVar8 < 3))))
            {
              uVar4 = uVar4 ^ uVar4 >> 1;
            }
            iVar12 = iVar12 + 4;
            *(undefined4 *)(*(int *)(param_1 + 0x60) + -4 + iVar12) =
                 *(undefined4 *)(*(int *)(param_1 + 0x60) + (uVar4 % uVar8) * 4);
            *(undefined4 *)(*(int *)(param_1 + 0x60) + (uVar4 % uVar8) * 4) = uVar6;
            bVar3 = (int)uVar8 < iVar11;
            uVar8 = uVar8 + 1;
          } while (bVar3);
        }
        if (0 < iVar2) {
          iVar12 = 0;
          uVar8 = 1;
          do {
            uVar6 = *(undefined4 *)(iVar12 + *(int *)(param_1 + 0x74));
            uVar4 = *(int *)(param_1 + 0x90) * 0x19660d + 0x3c6ef35f;
            *(uint *)(param_1 + 0x90) = uVar4;
            if (((uVar8 < 0x10001) && (uVar4 = uVar4 ^ uVar4 >> 0x10, uVar8 < 0x101)) &&
               ((uVar4 = uVar4 ^ uVar4 >> 8, uVar8 < 0x11 &&
                ((uVar4 = uVar4 ^ uVar4 >> 4, uVar8 < 5 && (uVar4 = uVar4 ^ uVar4 >> 2, uVar8 < 3)))
                ))) {
              uVar4 = uVar4 ^ uVar4 >> 1;
            }
            iVar12 = iVar12 + 4;
            *(undefined4 *)(*(int *)(param_1 + 0x74) + -4 + iVar12) =
                 *(undefined4 *)(*(int *)(param_1 + 0x74) + (uVar4 % uVar8) * 4);
            *(undefined4 *)(*(int *)(param_1 + 0x74) + (uVar4 % uVar8) * 4) = uVar6;
            bVar3 = (int)uVar8 < iVar2;
            uVar8 = uVar8 + 1;
          } while (bVar3);
        }
      }
      if ((*(uint *)(in_stack_0000001c + 0x3c) & 0x100) == 0) {
        iVar12 = 0;
        if (0 < *(int *)(param_1 + 0x30)) {
          iVar9 = 0;
          do {
            iVar5 = *(int *)(param_1 + 0x38) + iVar9;
            FUN_00636b70(*(int *)(iVar5 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                         *(int *)(iVar5 + 0x6c) * 0x68 + *(int *)(param_1 + 0x10),iVar5);
            iVar12 = iVar12 + 1;
            iVar9 = iVar9 + 0x88;
          } while (iVar12 < *(int *)(param_1 + 0x30));
        }
        if (0 < in_stack_00000018) {
          local_1b0 = in_stack_00000018;
          piVar10 = in_stack_00000014;
          do {
            iVar12 = *(int *)(*piVar10 + 0x14);
            iVar9 = *(int *)(iVar12 + 0xd0);
            if (iVar9 < 0) {
              if (((*(int *)(iVar12 + 0xe8) == 2) && (iVar12 != 0)) &&
                 (*(float *)(iVar12 + 0x150) != _DAT_007d5344)) {
                iVar9 = *(int *)(param_1 + 8);
                uVar6 = FUN_0063ac90(auStack_138);
                FUN_006371f0(uVar6,iVar12);
                *(int *)(iVar12 + 0xd0) = iVar9;
              }
              else {
                iVar9 = 0;
              }
            }
            iVar12 = *(int *)(*piVar10 + 0x18);
            iVar5 = *(int *)(iVar12 + 0xd0);
            if (iVar5 < 0) {
              if (((*(int *)(iVar12 + 0xe8) == 2) && (iVar12 != 0)) &&
                 (*(float *)(iVar12 + 0x150) != _DAT_007d5344)) {
                iVar5 = *(int *)(param_1 + 8);
                uVar6 = FUN_0063ac90(auStack_68);
                FUN_006371f0(uVar6,iVar12);
                *(int *)(iVar12 + 0xd0) = iVar5;
              }
              else {
                iVar5 = 0;
              }
            }
            (**(code **)(*(int *)*piVar10 + 0x14))
                      (iVar9 * 0x68 + *(int *)(param_1 + 0x10),
                       iVar5 * 0x68 + *(int *)(param_1 + 0x10),
                       *(undefined4 *)(in_stack_0000001c + 0xc));
            piVar10 = piVar10 + 1;
            local_1b0 = local_1b0 + -1;
          } while (local_1b0 != 0);
        }
        iVar12 = *(int *)(param_1 + 0x1c);
        iVar9 = 0;
        if (0 < iVar12) {
          do {
            iVar5 = *(int *)(*(int *)(param_1 + 0x60) + iVar9 * 4) * 0x88;
            iVar7 = iVar5 + *(int *)(param_1 + 0x24);
            FUN_00636d90(*(int *)(iVar7 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                         *(int *)(iVar5 + 0x6c + *(int *)(param_1 + 0x24)) * 0x68 +
                         *(int *)(param_1 + 0x10),iVar7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar12);
        }
        iVar12 = *(int *)(param_1 + 0x44);
        iVar9 = 0;
        if (0 < iVar12) {
          do {
            iVar5 = *(int *)(*(int *)(param_1 + 0x74) + iVar9 * 4) * 0x88;
            iVar7 = iVar5 + *(int *)(param_1 + 0x4c);
            fVar1 = *(float *)(*(int *)(iVar5 + 100 + *(int *)(param_1 + 0x4c)) * 0x88 + 0x54 +
                              *(int *)(param_1 + 0x24));
            if (_DAT_007d5344 < fVar1) {
              fVar1 = fVar1 * *(float *)(iVar7 + 0x58);
              *(float *)(iVar7 + 0x7c) = -fVar1;
              *(float *)(iVar7 + 0x80) = fVar1;
              FUN_00636b70(*(int *)(iVar7 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                           *(int *)(iVar7 + 0x6c) * 0x68 + *(int *)(param_1 + 0x10),iVar7);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar12);
        }
      }
      else {
        iVar12 = 0;
        if (0 < *(int *)(param_1 + 0x30)) {
          iVar9 = 0;
          do {
            iVar5 = *(int *)(param_1 + 0x38) + iVar9;
            FUN_00636b70(*(int *)(iVar5 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                         *(int *)(iVar5 + 0x6c) * 0x68 + *(int *)(param_1 + 0x10),iVar5);
            iVar12 = iVar12 + 1;
            iVar9 = iVar9 + 0x88;
          } while (iVar12 < *(int *)(param_1 + 0x30));
        }
        if (0 < in_stack_00000018) {
          local_1b0 = in_stack_00000018;
          piVar10 = in_stack_00000014;
          do {
            iVar12 = *(int *)(*piVar10 + 0x14);
            iVar9 = *(int *)(iVar12 + 0xd0);
            if (iVar9 < 0) {
              if (((*(int *)(iVar12 + 0xe8) == 2) && (iVar12 != 0)) &&
                 (*(float *)(iVar12 + 0x150) != _DAT_007d5344)) {
                iVar9 = *(int *)(param_1 + 8);
                uVar6 = FUN_0061ddb0();
                uVar6 = FUN_0063ac90(uVar6);
                FUN_006371f0(uVar6,iVar12);
                *(int *)(iVar12 + 0xd0) = iVar9;
              }
              else {
                iVar9 = 0;
              }
            }
            iVar12 = *(int *)(*piVar10 + 0x18);
            iVar5 = *(int *)(iVar12 + 0xd0);
            if (iVar5 < 0) {
              if (((*(int *)(iVar12 + 0xe8) == 2) && (iVar12 != 0)) &&
                 (*(float *)(iVar12 + 0x150) != _DAT_007d5344)) {
                iVar5 = *(int *)(param_1 + 8);
                uVar6 = FUN_0061ddb0();
                uVar6 = FUN_0063ac90(uVar6);
                FUN_006371f0(uVar6,iVar12);
                *(int *)(iVar12 + 0xd0) = iVar5;
              }
              else {
                iVar5 = 0;
              }
            }
            (**(code **)(*(int *)*piVar10 + 0x14))
                      (iVar9 * 0x68 + *(int *)(param_1 + 0x10),
                       iVar5 * 0x68 + *(int *)(param_1 + 0x10),
                       *(undefined4 *)(in_stack_0000001c + 0xc));
            piVar10 = piVar10 + 1;
            local_1b0 = local_1b0 + -1;
          } while (local_1b0 != 0);
        }
        iVar12 = *(int *)(param_1 + 0x1c);
        iVar9 = 0;
        if (0 < iVar12) {
          do {
            iVar5 = *(int *)(*(int *)(param_1 + 0x60) + iVar9 * 4) * 0x88;
            iVar7 = iVar5 + *(int *)(param_1 + 0x24);
            FUN_00636d90(*(int *)(iVar7 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                         *(int *)(iVar5 + 0x6c + *(int *)(param_1 + 0x24)) * 0x68 +
                         *(int *)(param_1 + 0x10),iVar7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar12);
        }
        iVar12 = *(int *)(param_1 + 0x44);
        iVar9 = 0;
        if (0 < iVar12) {
          do {
            iVar5 = *(int *)(*(int *)(param_1 + 0x74) + iVar9 * 4) * 0x88;
            iVar7 = iVar5 + *(int *)(param_1 + 0x4c);
            fVar1 = *(float *)(*(int *)(iVar5 + 100 + *(int *)(param_1 + 0x4c)) * 0x88 + 0x54 +
                              *(int *)(param_1 + 0x24));
            if (_DAT_007d5344 < fVar1) {
              fVar1 = fVar1 * *(float *)(iVar7 + 0x58);
              *(float *)(iVar7 + 0x7c) = -fVar1;
              *(float *)(iVar7 + 0x80) = fVar1;
              FUN_00636b70(*(int *)(iVar7 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                           *(int *)(iVar7 + 0x6c) * 0x68 + *(int *)(param_1 + 0x10),iVar7);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar12);
        }
      }
      local_1ac = local_1ac + 1;
    } while ((int)local_1ac < *(int *)(in_stack_0000001c + 0x14));
  }
  if (*(int *)(in_stack_0000001c + 0x2c) != 0) {
    if ((*(uint *)(in_stack_0000001c + 0x3c) & 0x100) == 0) {
      iVar11 = 0;
      if (0 < *(int *)(in_stack_0000001c + 0x14)) {
        do {
          iVar2 = *(int *)(param_1 + 0x1c);
          iVar12 = 0;
          if (0 < iVar2) {
            do {
              iVar9 = *(int *)(*(int *)(param_1 + 0x60) + iVar12 * 4) * 0x88;
              iVar5 = iVar9 + *(int *)(param_1 + 0x24);
              FUN_00636f70(*(int *)(iVar5 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                           *(int *)(iVar9 + 0x6c + *(int *)(param_1 + 0x24)) * 0x68 +
                           *(int *)(param_1 + 0x10),iVar5);
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar2);
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(in_stack_0000001c + 0x14));
      }
    }
    else {
      iVar11 = 0;
      if (0 < *(int *)(in_stack_0000001c + 0x14)) {
        do {
          iVar2 = *(int *)(param_1 + 0x1c);
          iVar12 = 0;
          if (0 < iVar2) {
            do {
              iVar9 = *(int *)(*(int *)(param_1 + 0x60) + iVar12 * 4) * 0x88;
              iVar5 = iVar9 + *(int *)(param_1 + 0x24);
              FUN_00636f70(*(int *)(iVar5 + 0x68) * 0x68 + *(int *)(param_1 + 0x10),
                           *(int *)(iVar9 + 0x6c + *(int *)(param_1 + 0x24)) * 0x68 +
                           *(int *)(param_1 + 0x10),iVar5);
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar2);
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(in_stack_0000001c + 0x14));
        return (float10)_DAT_007d5344;
      }
    }
  }
  return (float10)_DAT_007d5344;
}


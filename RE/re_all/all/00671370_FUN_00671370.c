
void FUN_00671370(int param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    FUN_00671170(param_1,param_2);
    if ((*(byte *)(param_2 + 8) & 8) == 0) {
      if (*(char *)(param_2 + 0x19) == '\x03') {
        FUN_00668620(param_1,s_Valid_palette_required_for_palet_00a0c868);
      }
    }
    else {
      FUN_00677790(param_1,*(undefined4 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x14));
    }
    if ((*(byte *)(param_2 + 8) & 0x10) != 0) {
      if ((((*(uint *)(param_1 + 0x7c) & 0x80000) != 0) && (*(char *)(param_2 + 0x19) == '\x03')) &&
         (iVar5 = 0, *(short *)(param_2 + 0x16) != 0)) {
        do {
          pcVar1 = (char *)(*(int *)(param_2 + 0x9c) + iVar5);
          pcVar2 = (char *)(*(int *)(param_2 + 0x9c) + iVar5);
          iVar5 = iVar5 + 1;
          *pcVar2 = -1 - *pcVar1;
        } while (iVar5 < (int)(uint)*(ushort *)(param_2 + 0x16));
      }
      FUN_00678680(param_1,*(undefined4 *)(param_2 + 0x9c),param_2 + 0xa0,
                   *(undefined2 *)(param_2 + 0x16),*(undefined1 *)(param_2 + 0x19));
    }
    if ((*(byte *)(param_2 + 8) & 0x20) != 0) {
      FUN_006787e0(param_1,param_2 + 0xaa,*(undefined1 *)(param_2 + 0x19));
    }
    if ((*(byte *)(param_2 + 8) & 0x40) != 0) {
      FUN_00678920(param_1,*(undefined4 *)(param_2 + 0xcc),*(undefined2 *)(param_2 + 0x14));
    }
    if ((*(uint *)(param_2 + 8) & 0x100) != 0) {
      FUN_00678db0(param_1,*(undefined4 *)(param_2 + 0xb4),*(undefined4 *)(param_2 + 0xb8),
                   *(undefined1 *)(param_2 + 0xbc));
    }
    if ((*(uint *)(param_2 + 8) & 0x400) != 0) {
      FUN_00678e10(param_1,*(undefined4 *)(param_2 + 0xd0),*(undefined4 *)(param_2 + 0xd4),
                   *(undefined4 *)(param_2 + 0xd8),*(undefined1 *)(param_2 + 0xe4),
                   *(undefined1 *)(param_2 + 0xe5),*(undefined4 *)(param_2 + 0xdc),
                   *(undefined4 *)(param_2 + 0xe0));
    }
    if ((*(uint *)(param_2 + 8) & 0x4000) != 0) {
      FUN_00678fb0(param_1,*(undefined1 *)(param_2 + 0xfc),*(undefined4 *)(param_2 + 0x100),
                   *(undefined4 *)(param_2 + 0x104));
    }
    if ((*(byte *)(param_2 + 8) & 0x80) != 0) {
      FUN_00679050(param_1,*(undefined4 *)(param_2 + 0xc0),*(undefined4 *)(param_2 + 0xc4),
                   *(undefined1 *)(param_2 + 200));
    }
    if ((*(uint *)(param_2 + 8) & 0x200) != 0) {
      FUN_006790b0(param_1,param_2 + 0x8c);
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0x200;
    }
    if (((*(uint *)(param_2 + 8) & 0x2000) != 0) && (iVar5 = 0, 0 < *(int *)(param_2 + 0xf8))) {
      iVar6 = 0;
      do {
        FUN_006783c0(param_1,*(int *)(param_2 + 0xf4) + iVar6);
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x10;
      } while (iVar5 < *(int *)(param_2 + 0xf8));
    }
    iVar5 = 0;
    if (0 < *(int *)(param_2 + 0x80)) {
      iVar6 = 0;
      do {
        iVar3 = iVar6 + *(int *)(param_2 + 0x88);
        iVar4 = *(int *)(iVar6 + *(int *)(param_2 + 0x88));
        if (iVar4 < 1) {
          if (iVar4 == 0) {
            FUN_00678a50(param_1,*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),0,0);
            *(undefined4 *)(iVar6 + *(int *)(param_2 + 0x88)) = 0xfffffffe;
          }
          else if (iVar4 == -1) {
            FUN_006789a0(param_1,*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 8),0);
            goto LAB_006715f0;
          }
        }
        else {
          FUN_00678b60(param_1,iVar4,*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0x14),
                       *(undefined4 *)(iVar3 + 0x18),*(undefined4 *)(iVar3 + 8));
LAB_006715f0:
          *(undefined4 *)(iVar6 + *(int *)(param_2 + 0x88)) = 0xfffffffd;
        }
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 0x1c;
      } while (iVar5 < *(int *)(param_2 + 0x80));
    }
    FUN_006712d0(param_1,param_2,2);
  }
  return;
}


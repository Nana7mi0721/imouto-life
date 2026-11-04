
void FUN_00669290(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x4000) != 0) {
      if (param_4 == -1) {
        iVar2 = 0;
        if (0 < *(int *)(param_2 + 0x80)) {
          do {
            FUN_00669290(param_1,param_2,0x4000,iVar2);
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_2 + 0x80));
        }
        FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x88));
        *(undefined4 *)(param_2 + 0x88) = 0;
        *(undefined4 *)(param_2 + 0x80) = 0;
      }
      else if (*(int *)(param_2 + 0x88) != 0) {
        iVar2 = *(int *)(*(int *)(param_2 + 0x88) + 4 + param_4 * 0x1c);
        if (iVar2 != 0) {
          FUN_0066cb60(param_1,iVar2);
          *(undefined4 *)(*(int *)(param_2 + 0x88) + 4 + param_4 * 0x1c) = 0;
        }
      }
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x2000) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x9c));
      *(undefined4 *)(param_2 + 0x9c) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffef;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x100) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x100));
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x104));
      *(undefined4 *)(param_2 + 0x100) = 0;
      *(undefined4 *)(param_2 + 0x104) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffbfff;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x80) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xd0));
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xdc));
      *(undefined4 *)(param_2 + 0xd0) = 0;
      *(undefined4 *)(param_2 + 0xdc) = 0;
      if (*(int *)(param_2 + 0xe0) != 0) {
        uVar1 = 0;
        if (*(char *)(param_2 + 0xe5) != '\0') {
          do {
            FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_2 + 0xe0) + uVar1 * 4));
            *(undefined4 *)(*(int *)(param_2 + 0xe0) + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
          } while (uVar1 < *(byte *)(param_2 + 0xe5));
        }
        FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xe0));
        *(undefined4 *)(param_2 + 0xe0) = 0;
      }
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffbff;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x10) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x74));
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x78));
      *(undefined4 *)(param_2 + 0x74) = 0;
      *(undefined4 *)(param_2 + 0x78) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffefff;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x20) != 0) {
      if (param_4 == -1) {
        if (*(int *)(param_2 + 0xf8) != 0) {
          iVar2 = 0;
          if (0 < *(int *)(param_2 + 0xf8)) {
            do {
              FUN_00669290(param_1,param_2,0x20,iVar2);
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(param_2 + 0xf8));
          }
          FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xf4));
          *(undefined4 *)(param_2 + 0xf4) = 0;
          *(undefined4 *)(param_2 + 0xf8) = 0;
        }
        *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffdfff;
      }
      else if (*(int *)(param_2 + 0xf4) != 0) {
        iVar2 = param_4 * 0x10;
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_2 + 0xf4) + iVar2));
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_2 + 0xf4) + 8 + iVar2));
        *(undefined4 *)(*(int *)(param_2 + 0xf4) + iVar2) = 0;
        *(undefined4 *)(*(int *)(param_2 + 0xf4) + 8 + iVar2) = 0;
      }
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x200) != 0) {
      if (param_4 == -1) {
        if (*(int *)(param_2 + 0xf0) != 0) {
          iVar2 = 0;
          if (0 < *(int *)(param_2 + 0xf0)) {
            do {
              FUN_00669290(param_1,param_2,0x200,iVar2);
              iVar2 = iVar2 + 1;
            } while (iVar2 < *(int *)(param_2 + 0xf0));
          }
          FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xec));
          *(undefined4 *)(param_2 + 0xec) = 0;
          *(undefined4 *)(param_2 + 0xf0) = 0;
        }
      }
      else if (*(int *)(param_2 + 0xec) != 0) {
        FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_2 + 0xec) + 8 + param_4 * 0x14));
        *(undefined4 *)(*(int *)(param_2 + 0xec) + 8 + param_4 * 0x14) = 0;
      }
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 8) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0xcc));
      *(undefined4 *)(param_2 + 0xcc) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffffffbf;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x1000) != 0) {
      FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x10));
      *(undefined4 *)(param_2 + 0x10) = 0;
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xfffffff7;
      *(undefined2 *)(param_2 + 0x14) = 0;
    }
    if ((*(uint *)(param_2 + 0xe8) & param_3 & 0x40) != 0) {
      if (*(int *)(param_2 + 0x108) != 0) {
        uVar1 = 0;
        if (*(int *)(param_2 + 4) != 0) {
          do {
            FUN_0066cb60(param_1,*(undefined4 *)(*(int *)(param_2 + 0x108) + uVar1 * 4));
            *(undefined4 *)(*(int *)(param_2 + 0x108) + uVar1 * 4) = 0;
            uVar1 = uVar1 + 1;
          } while (uVar1 < *(uint *)(param_2 + 4));
        }
        FUN_0066cb60(param_1,*(undefined4 *)(param_2 + 0x108));
        *(undefined4 *)(param_2 + 0x108) = 0;
      }
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) & 0xffff7fff;
    }
    if (param_4 != -1) {
      param_3 = param_3 & 0xffffbddf;
    }
    *(uint *)(param_2 + 0xe8) = *(uint *)(param_2 + 0xe8) & ~param_3;
  }
  return;
}


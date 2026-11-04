
void FUN_00690be0(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = param_1;
  iVar2 = *(int *)(param_1 + 0x10);
  if (param_3 == 0) {
    *(undefined4 *)(**(int **)(param_1 + 0x78) + 0x14) = 0x29;
    (**(code **)**(undefined4 **)(param_1 + 0x78))(*(undefined4 **)(param_1 + 0x78));
  }
  if (*(char *)(param_1 + 0x6c) == '\0') {
    uVar3 = iVar2 + param_3;
    param_1 = ((1 << ((byte)param_3 & 0x1f)) - 1U & param_2) << (0x18U - (char)uVar3 & 0x1f) |
              *(uint *)(param_1 + 0xc);
    if (7 < (int)uVar3) {
      param_3 = uVar3 >> 3;
      uVar3 = uVar3 + param_3 * -8;
      do {
        **(char **)(iVar1 + 0x70) = param_1._2_1_;
        iVar2 = *(int *)(iVar1 + 0x74) + -1;
        *(int *)(iVar1 + 0x70) = *(int *)(iVar1 + 0x70) + 1;
        *(int *)(iVar1 + 0x74) = iVar2;
        if (iVar2 == 0) {
          FUN_00690cc0(iVar1);
        }
        if (param_1._2_1_ == -1) {
          **(undefined1 **)(iVar1 + 0x70) = 0;
          iVar2 = *(int *)(iVar1 + 0x74) + -1;
          *(int *)(iVar1 + 0x70) = *(int *)(iVar1 + 0x70) + 1;
          *(int *)(iVar1 + 0x74) = iVar2;
          if (iVar2 == 0) {
            FUN_00690cc0(iVar1);
          }
        }
        param_1 = param_1 << 8;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
    *(uint *)(iVar1 + 0xc) = param_1;
    *(uint *)(iVar1 + 0x10) = uVar3;
  }
  return;
}


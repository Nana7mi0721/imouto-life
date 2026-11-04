
void FUN_00690e20(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x80) != 0) {
    iVar2 = 0;
    iVar1 = *(int *)(param_1 + 0x80) >> 1;
    if (iVar1 != 0) {
      do {
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 >> 1;
      } while (iVar1 != 0);
      if (0xe < iVar2) {
        *(undefined4 *)(**(int **)(param_1 + 0x78) + 0x14) = 0x29;
        (**(code **)**(undefined4 **)(param_1 + 0x78))(*(undefined4 **)(param_1 + 0x78));
      }
    }
    FUN_00690eb0(param_1,*(undefined4 *)(param_1 + 0x7c),iVar2 << 4);
    if (iVar2 != 0) {
      FUN_00690be0(param_1,*(undefined4 *)(param_1 + 0x80),iVar2);
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
    FUN_00690f00(param_1,*(undefined4 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x84));
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}



int FUN_006c0dc0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  iVar1 = FUN_006a8d90(param_1 + 0x88,param_1 + 0x1f0);
  if (iVar1 != 0) {
    puVar4 = (undefined4 *)(param_1 + 0x200);
    do {
      if (iVar1 < 0) {
        iVar3 = -3;
        break;
      }
      iVar1 = FUN_006c0e70(puVar4[-4],puVar4[-3]);
      *param_2 = iVar1;
      if (iVar1 < 1) {
        if (0 < iVar2) {
          puVar4[-8] = *puVar4;
          puVar4[-7] = puVar4[1];
        }
      }
      else {
        iVar3 = iVar3 + iVar1;
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 1;
        puVar4 = puVar4 + 8;
      }
      iVar1 = FUN_006a8d90(param_1 + 0x88,puVar4 + -4);
    } while (iVar1 != 0);
  }
  *(undefined4 *)(param_1 + 0x21d0) = 0;
  *(int *)(param_1 + 0x21d4) = iVar2;
  return iVar3;
}


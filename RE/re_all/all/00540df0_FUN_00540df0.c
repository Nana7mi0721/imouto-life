
int FUN_00540df0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  
  iVar1 = param_1;
  FUN_0056d380(param_3,0,0x440);
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x28)) {
    do {
      (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
      FUN_0056d380(param_3,0,0x440);
      iVar2 = (**(code **)(param_1 + iVar3 * 4))(param_2,param_3);
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x28));
  }
  if (iVar3 == *(int *)(param_1 + 0x28)) {
    param_1 = 0;
    if (DAT_00ddb334 != 0) {
      puVar4 = &DAT_00ddb334;
      do {
        (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
        FUN_0056d380(param_3,0,0x440);
        iVar3 = (*(code *)*puVar4)(param_2,param_3,*(undefined4 *)(iVar1 + 0x2c));
        if (iVar3 == 0) break;
        param_1 = param_1 + 1;
        puVar4 = &DAT_00ddb334 + param_1;
      } while ((&DAT_00ddb334)[param_1] != 0);
    }
    if ((&DAT_00ddb334)[param_1] == 0) {
      param_1 = 0;
      if (PTR_FUN_0084d0f0 != (undefined *)0x0) {
        ppuVar5 = &PTR_FUN_0084d0f0;
        do {
          (**(code **)(param_2 + 4))(*(undefined4 *)(param_2 + 0x18),0,0,0);
          FUN_0056d380(param_3,0,0x440);
          iVar3 = (*(code *)*ppuVar5)(param_2,param_3,*(undefined4 *)(iVar1 + 0x2c));
          if (iVar3 == 0) break;
          param_1 = param_1 + 1;
          ppuVar5 = &PTR_FUN_0084d0f0 + param_1;
        } while ((&PTR_FUN_0084d0f0)[param_1] != (undefined *)0x0);
      }
      return ((&PTR_FUN_0084d0f0)[param_1] != (undefined *)0x0) - 1;
    }
  }
  return 0;
}


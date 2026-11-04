
int FUN_005fadb0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_168 [90];
  
LAB_005fadc1:
  do {
    iVar1 = FUN_005fad70(param_1,0x1000);
    if (iVar1 == 0) {
LAB_005faead:
      iVar1 = *(int *)(param_1 + 0x4e0);
      do {
        if (2 < iVar1) {
          return (-(uint)(*(int *)(param_1 + 0x4e0) != 0) & 2) - 1;
        }
        while( true ) {
          iVar1 = FUN_006a8d90(param_1 + 0x298,param_1 + 0x400);
          if (iVar1 == 0) break;
          if (iVar1 < 0) {
            return -1;
          }
          iVar1 = FUN_006b8b90(param_1 + 0x420,param_1 + 0x488,param_1 + 0x400);
          if (iVar1 != 0) {
            return -1;
          }
          iVar1 = *(int *)(param_1 + 0x4e0) + 1;
          *(int *)(param_1 + 0x4e0) = iVar1;
          if ((iVar1 == 3) || (2 < iVar1)) break;
        }
        iVar1 = FUN_006a8940(param_1 + 0x26c,param_1 + 0x288);
        if (iVar1 < 1) {
          iVar1 = FUN_005fad70(param_1,0x1000);
          if (iVar1 == 0) {
            return -1;
          }
        }
        else {
          FUN_006a89a0(param_1 + 0x298,param_1 + 0x288);
        }
        iVar1 = *(int *)(param_1 + 0x4e0);
      } while( true );
    }
    iVar1 = param_1 + 0x288;
    iVar2 = FUN_006a8940(param_1 + 0x26c,iVar1);
    if (iVar2 == 1) {
LAB_005fadf2:
      iVar2 = FUN_006a8260(iVar1);
      if (iVar2 == 0) {
        FUN_006a89a0(param_1 + 0x298,param_1 + 0x288);
      }
      else {
        uVar3 = FUN_006a8360(iVar1);
        FUN_006a83f0(local_168,uVar3);
        FUN_006a89a0(local_168,iVar1);
        FUN_006a8d90(local_168,param_1 + 0x400);
        iVar2 = FUN_006b8b90(param_1 + 0x420,param_1 + 0x488,param_1 + 0x400);
        if (iVar2 != 0) break;
        uVar3 = FUN_006a8360(param_1 + 0x288);
        *(undefined4 *)(param_1 + 0x4b0) = uVar3;
        *(undefined4 *)(param_1 + 0x4e0) = 1;
        puVar4 = local_168;
        puVar5 = (undefined4 *)(param_1 + 0x298);
        for (iVar1 = 0x5a; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar5 = *puVar4;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        }
      }
      goto LAB_005faead;
    }
  } while( true );
  FUN_006a8490(local_168);
  iVar2 = FUN_006a8940(param_1 + 0x26c,iVar1);
  if (iVar2 != 1) goto LAB_005fadc1;
  goto LAB_005fadf2;
}


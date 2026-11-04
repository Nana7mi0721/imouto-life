
void FUN_00677850(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x80) != 0x49444154) {
    if (*(int *)(param_1 + 0xbc) == 0) {
      puVar1 = (undefined4 *)FUN_0066caf0(param_1,*(int *)(param_1 + 0xc0) + 4);
      *(undefined4 **)(param_1 + 0xbc) = puVar1;
      *puVar1 = 0;
    }
    else {
      FUN_00677480(param_1,*(int *)(param_1 + 0xbc));
    }
    uVar2 = FUN_00677a70(param_1);
    iVar3 = FUN_00677c50(param_1,0x49444154,uVar2);
    if (iVar3 != 0) {
      FUN_00668620(param_1,*(undefined4 *)(param_1 + 0x9c));
    }
    *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0xc0);
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0xbc) + 4;
  }
  *(undefined4 *)(param_1 + 0x84) = param_2;
  *(undefined4 *)(param_1 + 0x88) = 0;
LAB_006778f5:
  do {
    iVar3 = -1;
    if (param_3 != -1) {
      iVar3 = param_3;
    }
    *(int *)(param_1 + 0x88) = iVar3;
    iVar4 = FUN_0067cde0(param_1 + 0x84,~-(uint)(param_3 - iVar3 != 0) & param_4);
    param_3 = (param_3 - iVar3) + *(int *)(param_1 + 0x88);
    *(undefined4 *)(param_1 + 0x88) = 0;
    if (*(int *)(param_1 + 0x94) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0xc0);
      iVar3 = *(int *)(param_1 + 0xbc) + 4;
      if (((*(byte *)(param_1 + 0x74) & 4) == 0) && (*(char *)(param_1 + 0x28c) == '\0')) {
        uVar5 = FUN_00677a70(param_1);
        FUN_00677be0(iVar3,uVar5);
      }
      FUN_00677430(param_1,0x49444154,iVar3,uVar2);
      *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 4;
      *(int *)(param_1 + 0x90) = iVar3;
      *(undefined4 *)(param_1 + 0x94) = uVar2;
      if (iVar4 != 0) {
LAB_006779c1:
        if ((iVar4 == 1) && (param_4 == 4)) {
          iVar3 = *(int *)(param_1 + 0xc0);
          iVar4 = *(int *)(param_1 + 0x94);
          iVar6 = *(int *)(param_1 + 0xbc) + 4;
          if (((*(byte *)(param_1 + 0x74) & 4) == 0) && (*(char *)(param_1 + 0x28c) == '\0')) {
            uVar2 = FUN_00677a70(param_1);
            FUN_00677be0(iVar6,uVar2);
          }
          FUN_00677430(param_1,0x49444154,iVar6,iVar3 - iVar4);
          *(undefined4 *)(param_1 + 0x94) = 0;
          *(undefined4 *)(param_1 + 0x90) = 0;
          *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) | 0xc;
          *(undefined4 *)(param_1 + 0x80) = 0;
          return;
        }
        FUN_00669790(param_1,iVar4);
        FUN_00668620(param_1,*(undefined4 *)(param_1 + 0x9c));
        goto LAB_006778f5;
      }
      if (param_4 != 0) goto LAB_006778f5;
    }
    else if (iVar4 != 0) goto LAB_006779c1;
    if (param_3 == 0) {
      if (param_4 == 4) {
        FUN_00668620(param_1,s_Z_OK_on_Z_FINISH_with_output_spa_00a0d470);
        return;
      }
      return;
    }
  } while( true );
}


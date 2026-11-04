
undefined4 FUN_005ca7b0(int param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  undefined4 local_204;
  undefined4 local_200;
  undefined1 local_1fc [508];
  
  local_200 = 0;
  _memset(local_1fc,0,0x1fc);
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00f3a070 != 0) {
    if (DAT_00ef7314 == 0) {
      if (DAT_00ef7324 == 0) goto LAB_005ca866;
    }
    else if ((DAT_00ef7324 == 0) && (FUN_00568ca0(0), DAT_00dda46c != 0)) {
      FUN_00584d70();
    }
    DAT_00ef72e8 = 1;
    if (DAT_00ef7314 != 0) {
      DAT_00ef72e4 = 1;
    }
    DAT_00ef7314 = 0;
    DAT_00ef7318 = 0;
    DAT_00ef72cc = 1;
  }
LAB_005ca866:
  FUN_005bba30(0,0x80,&local_200);
  if ((in_EAX != 0) && (piVar1 = (int *)**(int **)(in_EAX + 0x100), *piVar1 != 0)) {
    FUN_005d2e50(piVar1[1],DAT_00a38140,*piVar1,DAT_00a38140,
                 *(undefined4 *)(&DAT_00ee9a58 + *(int *)(*(int *)(in_EAX + 0x4c) + 4) * 4));
  }
  if ((DAT_00ca39f4 == 0) || (DAT_00f3a188 == 0)) {
    if (param_1 == 0) {
      if (unaff_EBX == 0) {
        if (param_2 != 0) {
          local_204 = 0;
          FUN_005d23c0(param_2,&local_204);
          FUN_005c2b20(local_204,param_2,0);
          thunk_FUN_00567d80();
          return 0;
        }
        if (DAT_00ef1b58 == 0) {
          iVar2 = DAT_00ee9b90;
          iVar3 = DAT_00ee9bc4;
        }
        else {
          iVar2 = DAT_00ef1b58;
          iVar3 = DAT_00ef1b5c;
        }
      }
      else {
        iVar3 = *(int *)(*(int *)(**(int **)(unaff_EBX + 0x100) + 0xc) +
                        (*(int *)(*(int *)(unaff_EBX + 0x4c) + 0x34) * DAT_00a38140 + DAT_00a38160)
                        * 4);
        iVar2 = *(int *)(**(int **)(unaff_EBX + 0x100) + 4);
      }
    }
    else {
      iVar3 = (*(int **)(param_1 + 0x450))[2];
      iVar2 = **(int **)(param_1 + 0x450);
    }
  }
  else {
    iVar2 = DAT_00f3a188;
    iVar3 = DAT_00f3a190;
  }
  FUN_005c2b20(iVar2,iVar3,0);
  thunk_FUN_00567d80();
  return 0;
}


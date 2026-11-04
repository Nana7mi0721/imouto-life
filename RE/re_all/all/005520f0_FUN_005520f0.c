
undefined4 FUN_005520f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  uint unaff_EDI;
  int local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 local_488;
  int local_484;
  undefined1 local_480 [20];
  undefined1 local_46c [1132];
  
  local_4a4 = 0;
  iVar2 = FUN_0057e0e0();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if ((((DAT_00cc50a0 != 0) && (-1 < (int)unaff_EDI)) && ((unaff_EDI & 0x7c000000) == DAT_00cc50c8))
     && ((((int)(unaff_EDI & 0xffff) < DAT_00cc50d0 &&
          (piVar1 = *(int **)(DAT_00cc50a4 + (unaff_EDI & 0xffff) * 4), piVar1 != (int *)0x0)) &&
         (*piVar1 * 0x10000 == (unaff_EDI & 0x3ff0000))))) {
    if (unaff_EBX == 0) {
      local_484 = FUN_0052d000(param_2,param_3);
      puVar3 = (undefined4 *)FUN_0052c7a0();
      local_49c = *puVar3;
      local_498 = puVar3[1];
      local_494 = puVar3[2];
      local_490 = puVar3[3];
      local_48c = puVar3[4];
      local_488 = puVar3[5];
    }
    else {
      local_484 = thunk_FUN_00572540();
      if (local_484 == 0) {
        return 0xffffffff;
      }
      puVar3 = (undefined4 *)FUN_0052c790();
      local_49c = *puVar3;
      local_498 = puVar3[1];
      local_494 = puVar3[2];
      local_490 = puVar3[3];
      local_48c = puVar3[4];
      local_488 = puVar3[5];
    }
    FUN_0056d380(local_46c,0,0x46c);
    iVar2 = FUN_00597260(local_46c,&local_49c,*(undefined4 *)(param_1 + 0x30),
                         *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38));
    if (iVar2 < 0) {
      FUN_0056bca0(&DAT_007d6260);
    }
    else {
      iVar2 = FUN_005971c0(local_46c,local_480,&local_4a4,&local_4a0);
      if (iVar2 < 0) {
        FUN_0056bca0(&DAT_007d6218);
      }
      else {
        FUN_00597060(local_46c);
        if (unaff_EBX == 0) {
          FUN_0052d050(local_484);
        }
        else {
          thunk_FUN_00571d20(local_484);
        }
        local_484 = 0;
        iVar2 = FUN_00551e70();
        if (-1 < iVar2) {
          FUN_0056d420(piVar1[0x13],local_4a4,local_4a0);
          if (local_4a4 != 0) {
            FUN_0056e1d0(local_4a4);
          }
          return 0;
        }
      }
    }
    if (local_484 != 0) {
      if (unaff_EBX == 0) {
        FUN_0052d050(local_484);
      }
      else {
        thunk_FUN_00571d20();
      }
    }
    FUN_00597060(local_46c);
    if (local_4a4 != 0) {
      FUN_0056e1d0(local_4a4);
    }
  }
  return 0xffffffff;
}


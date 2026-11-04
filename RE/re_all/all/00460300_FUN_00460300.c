
undefined4 FUN_00460300(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_8;
  
  piVar1 = (int *)FUN_004ce990(1);
  if (*piVar1 == -1000000) {
    FUN_004f09c0(&DAT_00a180c0);
  }
  else {
    puVar2 = (undefined4 *)FUN_004ce990(1);
    local_8 = FUN_00487080(*puVar2);
    piVar1 = (int *)FUN_004ce990(1);
    if (*piVar1 < 1000000) {
      local_8 = FUN_00420d60(local_8);
    }
    iVar3 = FUN_004ce080();
    if ((local_8 < iVar3) && (-1 < local_8)) {
      puVar2 = (undefined4 *)FUN_004ce990(2);
      puVar4 = (undefined4 *)FUN_004ce990(local_8);
      *puVar4 = *puVar2;
    }
  }
  DAT_00a140cc = 1;
  return 1;
}


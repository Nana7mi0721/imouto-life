
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005217e0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  int local_48;
  int local_44;
  
  iVar4 = param_2;
  iVar3 = param_1;
  FUN_00568ca0();
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  if (DAT_00ca39e8 != 0) {
    if (DAT_00ca39f4 != 0) {
      FUN_0057ae10(DAT_00a38194,DAT_00a38198,DAT_00a3819c,DAT_00a381a0);
    }
    DAT_00ca39e8 = 0;
  }
  DAT_00a38188 = param_2;
  DAT_00a38184 = param_1;
  DAT_00a3818c = param_3;
  DAT_00a38190 = param_4;
  if ((DAT_00a38120 == 0xfffffffc) || (DAT_00a38120 == 0xfffffffe)) {
    local_44 = DAT_00a37e64;
    local_48 = DAT_00a37e60;
  }
  else if (((((DAT_00cc47d0 == 0) || ((int)DAT_00a38120 < 0)) ||
            ((DAT_00a38120 & 0x7c000000) != DAT_00cc47f8)) ||
           ((DAT_00cc4800 <= (int)(DAT_00a38120 & 0xffff) ||
            (piVar1 = *(int **)(DAT_00cc47d4 + (DAT_00a38120 & 0xffff) * 4), piVar1 == (int *)0x0)))
           ) || ((*piVar1 * 0x10000 != (DAT_00a38120 & 0x3ff0000) || (piVar1[4] != 0)))) {
    if ((((DAT_00cc79c0 == 0) || ((int)DAT_00a38120 < 0)) ||
        (((DAT_00a38120 & 0x7c000000) != DAT_00cc79e8 ||
         (((DAT_00cc79f0 <= (int)(DAT_00a38120 & 0xffff) ||
           (piVar1 = *(int **)(DAT_00cc79c4 + (DAT_00a38120 & 0xffff) * 4), piVar1 == (int *)0x0))
          || (*piVar1 * 0x10000 != (DAT_00a38120 & 0x3ff0000))))))) || (piVar1[4] != 0)) {
      return 0xffffffff;
    }
    local_48 = piVar1[0x48];
    local_44 = piVar1[0x49];
  }
  else {
    FUN_005185c0();
  }
  if (param_3 < param_1) {
    param_1 = param_3;
    param_3 = iVar3;
  }
  if (param_4 < param_2) {
    param_2 = param_4;
    param_4 = iVar4;
  }
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (local_48 < param_1) {
    param_1 = local_48;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (local_48 < param_3) {
    param_3 = local_48;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (local_44 < param_2) {
    param_2 = local_44;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (local_44 < param_4) {
    param_4 = local_44;
  }
  DAT_00a381a4 = (float)param_1;
  DAT_00a381a8 = (float)param_2;
  DAT_00a381ac = (float)param_3;
  DAT_00a381b0 = (float)param_4;
  DAT_00a38194 = param_1;
  DAT_00a38198 = param_2;
  DAT_00a3819c = param_3;
  DAT_00a381a0 = param_4;
  FUN_005811b0();
  if ((param_1 == param_3) || (param_2 == param_4)) {
    DAT_00a37fd0 = 1;
    return 0;
  }
  DAT_00a37fd0 = 0;
  if ((DAT_00a37d90 == 0) &&
     ((DAT_00a37d94 == 0 ||
      ((DAT_00ca39f4 == 0 && ((DAT_00a38120 == 0xfffffffe || (DAT_00a38120 == 0xfffffffc)))))))) {
    dVar2 = (double)(DAT_00a381a0 - DAT_00a38198);
    dVar5 = (double)(DAT_00a381a0 - DAT_00a38198);
  }
  else {
    dVar2 = (double)(DAT_00a381a0 - DAT_00a38198);
    dVar5 = -dVar2;
  }
  local_44 = DAT_00a3819c - DAT_00a38194;
  FUN_00586020(&DAT_00a38598,(double)local_44 * _DAT_00804a60 + (double)DAT_00a38194,
               (double)DAT_00a38198 + dVar2 * _DAT_00804a60,(double)local_44,dVar5);
  FUN_005857a0(&DAT_00a38658,&DAT_00a38598);
  DAT_00a381c4 = 0;
  DAT_00a38288 = 0;
  DAT_00a38418 = 0;
  FUN_00584ff0(&DAT_00a386d8,&DAT_00a38658);
  FUN_00584ff0(&DAT_00a38618,&DAT_00a38598);
  if (DAT_00a37d78 != 0) {
    FUN_00567e20(param_1,param_2,param_3,param_4);
  }
  return 0;
}


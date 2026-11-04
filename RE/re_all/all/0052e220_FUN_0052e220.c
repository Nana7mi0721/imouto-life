
uint FUN_0052e220(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_804;
  undefined1 local_800 [2048];
  
  if (DAT_00a496f0 == 0) {
    FUN_0052de90();
  }
  uVar3 = FUN_005809a0(0x11,0,0xffffffff);
  if ((((uVar3 == 0xffffffff) || (DAT_00cc76d0 == 0)) || ((int)uVar3 < 0)) ||
     ((((uVar3 & 0x7c000000) != DAT_00cc76f8 || (DAT_00cc7700 <= (int)(uVar3 & 0xffff))) ||
      ((piVar2 = *(int **)(DAT_00cc76d4 + (uVar3 & 0xffff) * 4), piVar2 == (int *)0x0 ||
       (*piVar2 * 0x10000 != (uVar3 & 0x3ff0000))))))) {
    return 0;
  }
  piVar2[0xc] = 0;
  if (param_3 == 0) {
    iVar5 = FUN_0052c820(param_2,0);
    if (iVar5 < 0) goto LAB_0052e3a8;
  }
  else {
    FUN_0052d510(param_1,local_800,0x800);
    local_804 = 0;
    FUN_0057fb10(0,&local_804,uVar3);
    FUN_0057fb30(0,&local_804,local_800);
    FUN_0057fb10(0,&local_804,param_2);
    puVar4 = (undefined4 *)FUN_0057fa80(local_804);
    if (puVar4 == (undefined4 *)0x0) {
LAB_0052e3a8:
      FUN_00580b80(uVar3);
      return 0;
    }
    puVar4[3] = &LAB_0052c930;
    local_804 = 0;
    puVar1 = puVar4 + 4;
    FUN_0057fb10(puVar1,&local_804,uVar3);
    FUN_0057fb30(puVar1,&local_804,local_800);
    FUN_0057fb10(puVar1,&local_804,param_2);
    iVar5 = FUN_00580290(puVar4);
    if (iVar5 < 0) {
      FUN_0056e1d0(puVar4);
      FUN_00580b80(uVar3);
      return 0;
    }
    FUN_00580610(uVar3,*puVar4);
  }
  return uVar3;
}


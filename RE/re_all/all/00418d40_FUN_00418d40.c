
bool __thiscall FUN_00418d40(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined1 *puVar4;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 local_c [4];
  int local_8;
  
  iVar1 = FUN_0046f600(param_2);
  bVar3 = iVar1 != -1;
  if (bVar3) {
    puVar4 = local_10;
    local_8 = iVar1;
    FUN_004ce060(local_c);
    puVar2 = (undefined4 *)FUN_004cf770(puVar4,iVar1);
    FUN_004cf710(local_14,*puVar2);
    *(undefined1 *)(param_1 + param_2) = 0;
    *(int *)(param_1 + 0x1428) = *(int *)(param_1 + 0x1428) + -1;
  }
  return bVar3;
}



void FUN_0068fd20(int param_1,char param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x68);
  *(undefined4 **)(param_1 + 0x184) = puVar1;
  *puVar1 = FUN_0068fdf0;
  if (param_2 == '\0') {
    iVar3 = (**(code **)(*(int *)(param_1 + 4) + 4))(param_1,1,0x500);
    piVar4 = puVar1 + 6;
    iVar5 = 10;
    do {
      *piVar4 = iVar3;
      piVar4 = piVar4 + 1;
      iVar3 = iVar3 + 0x80;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    puVar1[0x10] = 0;
  }
  else {
    _param_2 = 0;
    if (0 < *(int *)(param_1 + 0x4c)) {
      puVar6 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0xc);
      puVar1 = puVar1 + 0x10;
      do {
        iVar3 = *(int *)(param_1 + 4);
        uVar2 = FUN_006848c0(puVar6[5],*puVar6,*puVar6);
        uVar2 = FUN_006848c0(puVar6[4],puVar6[-1],uVar2);
        uVar2 = (**(code **)(iVar3 + 0x14))(param_1,1,0,uVar2);
        *puVar1 = uVar2;
        _param_2 = _param_2 + 1;
        puVar1 = puVar1 + 1;
        puVar6 = puVar6 + 0x16;
      } while (_param_2 < *(int *)(param_1 + 0x4c));
      return;
    }
  }
  return;
}


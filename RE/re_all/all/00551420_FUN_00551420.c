
void FUN_00551420(uint param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  iVar1 = param_1 + 0x20;
  if (param_2 != 0) {
    iVar1 = param_1 * 3 + 0x40;
  }
  puVar2 = (uint *)FUN_0056e030(iVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0x1faf);
  if (puVar2 == (uint *)0x0) {
    return;
  }
  uVar3 = (int)puVar2 + 0x1fU & 0xfffffff0;
  *puVar2 = uVar3;
  puVar2[2] = param_1;
  puVar2[3] = 1;
  if (param_2 == 0) {
    puVar2[1] = 0;
    return;
  }
  puVar2[1] = uVar3 + 0xf + param_1 & 0xfffffff0;
  return;
}


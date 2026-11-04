
undefined4 * FUN_0052d000(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           FUN_0056e030(0x10,"..\\..\\..\\..\\Source\\Library\\Main\\DxFile.cpp",0x12d7);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_0056d380(puVar1,0,0x10);
  *puVar1 = param_1;
  puVar1[2] = 0;
  puVar1[1] = param_2;
  puVar1[3] = 0;
  return puVar1;
}


function checkIfInstanceOf(obj: any, classFunction: any): boolean {
 if (obj == null || typeof classFunction !== 'function' ) return false;
    return Object(obj) instanceof classFunction;
};
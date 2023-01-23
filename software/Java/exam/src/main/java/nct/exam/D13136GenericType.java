package nct.exam;

import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;

/**
 * X&lt;Y&gt;型の型情報を保存します。
 *
 * @see java.lang.reflect.ParameterizedType ParameterizedType
 * @author dorayaki4369
 */
public class D13136GenericType<X, Y> implements ParameterizedType {
	private final Class<X> containner;
	private final Class<Y> wrapped;

	public D13136GenericType(Class<X> containner, Class<Y> wrapped) {
		this.containner = containner;
		this.wrapped = wrapped;
	}

	@Override
	public Type[] getActualTypeArguments() {
		return new Type[] { wrapped };
	}

	@Override
	public Type getOwnerType() {
		return containner;
	}

	@Override
	public Type getRawType() {
		return containner;
	}
}
